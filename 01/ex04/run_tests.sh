#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PASS=0
FAIL=0

check_pass() {
    echo -e "${GREEN}PASS${NC}: $1"
    ((PASS++))
}

check_fail() {
    echo -e "${RED}FAIL${NC}: $1"
    ((FAIL++))
}

# ============================================
# SELF-CREATING TEST FILES
# ============================================

create_test_files() {
    if [ ! -f "test1.txt" ]; then
        cat > test1.txt << 'EOF'
Hello world!
This is a test file.
Hello again, world!
Say hello to everyone.
EOF
    fi

    if [ ! -f "test2.txt" ]; then
        cat > test2.txt << 'EOF'
aaa bbb aaa ccc aaa
aaa aaa aaa
EOF
    fi

    if [ ! -f "test3.txt" ]; then
        cat > test3.txt << 'EOF'
The quick brown fox jumps over the lazy dog.
EOF
    fi

    if [ ! -f "test4.txt" ]; then
        printf 'Line 1\n\nLine 3 with\ttab\nLine 4 with special chars: !@#$%%^&*()\n' > test4.txt
    fi

    if [ ! -f "test5.txt" ]; then
        cat > test5.txt << 'EOF'
START middle END
START
END
STARTEND
EOF
    fi

    if [ ! -f "empty.txt" ]; then
        > empty.txt
    fi

    if [ ! -f "test7.txt" ]; then
        cat > test7.txt << 'EOF'
hello world hello
EOF
    fi

    if [ ! -f "test8.txt" ]; then
        cat > test8.txt << 'EOF'
The quick brown fox
EOF
    fi

    if [ ! -f "test9.txt" ]; then
        cat > test9.txt << 'EOF'
replace_me
EOF
    fi

    if [ ! -f "test10.txt" ]; then
        cat > test10.txt << 'EOF'
aaaa
EOF
    fi

    if [ ! -f "test11.txt" ]; then
        cat > test11.txt << 'EOF'
line one
line two
line three
EOF
    fi

    if [ ! -f "test12.txt" ]; then
        cat > test12.txt << 'EOF'
abc abc abc abc abc abc abc abc abc abc
EOF
    fi

    if [ ! -f "test13.txt" ]; then
        cat > test13.txt << 'EOF'
a,b,c,d,e
EOF
    fi
}

verify_binary() {
    if [ ! -f "./minised" ]; then
        echo -e "${RED}ERROR: ./minised not found!${NC}"
        echo "Please build the project first with: make"
        exit 1
    fi
    if [ ! -x "./minised" ]; then
        chmod +x ./minised
    fi
}

# Compare two files byte-for-byte
# Returns 0 if identical, 1 if different
compare_files() {
    cmp -s "$1" "$2"
}

# Create a temp file with expected content using printf
# This preserves all bytes including trailing newlines
make_expected_file() {
    printf '%s' "$2" > "$1"
}

echo "========================================"
echo "  Sed is for Losers - Test Suite"
echo "========================================"
echo ""

create_test_files
verify_binary

echo -e "${YELLOW}=== FUNCTIONAL TESTS ===${NC}"
echo ""

# Test 1: Basic replacement
echo "Test 1: Basic replacement (hello -> hi)"
./minised test1.txt "hello" "hi"
if [ $? -eq 0 ] && [ -f "test1.txt.replace" ]; then
    make_expected_file "/tmp/expected_1.txt" 'Hello world!
This is a test file.
Hello again, world!
Say hi to everyone.
'
    if compare_files "/tmp/expected_1.txt" "test1.txt.replace"; then
        check_pass "Basic replacement works correctly"
    else
        check_fail "Output mismatch for basic replacement"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_1.txt"
        echo "Actual (cat -A):"
        cat -A "test1.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 2: Multiple occurrences
echo "Test 2: Multiple occurrences (aaa -> XXX)"
./minised test2.txt "aaa" "XXX"
if [ $? -eq 0 ] && [ -f "test2.txt.replace" ]; then
    make_expected_file "/tmp/expected_2.txt" 'XXX bbb XXX ccc XXX
XXX XXX XXX
'
    if compare_files "/tmp/expected_2.txt" "test2.txt.replace"; then
        check_pass "Multiple same-line replacements work"
    else
        check_fail "Output mismatch for multiple occurrences"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_2.txt"
        echo "Actual (cat -A):"
        cat -A "test2.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 3: Empty s2
echo "Test 3: Replace with empty string (quick -> '')"
./minised test3.txt "quick" ""
if [ $? -eq 0 ] && [ -f "test3.txt.replace" ]; then
    make_expected_file "/tmp/expected_3.txt" 'The  brown fox jumps over the lazy dog.
'
    if compare_files "/tmp/expected_3.txt" "test3.txt.replace"; then
        check_pass "Empty s2 replacement (deletion) works"
    else
        check_fail "Output mismatch for empty s2"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_3.txt"
        echo "Actual (cat -A):"
        cat -A "test3.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 4: Tab character
echo "Test 4: Tab character replacement (\\t -> [TAB])"
./minised test4.txt "$(printf '\t')" "[TAB]"
if [ $? -eq 0 ] && [ -f "test4.txt.replace" ]; then
    make_expected_file "/tmp/expected_4.txt" 'Line 1

Line 3 with[TAB]tab
Line 4 with special chars: !@#$%^&*()
'
    if compare_files "/tmp/expected_4.txt" "test4.txt.replace"; then
        check_pass "Tab character replacement works"
    else
        check_fail "Output mismatch for tab replacement"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_4.txt"
        echo "Actual (cat -A):"
        cat -A "test4.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 5: Boundaries
echo "Test 5: Boundary replacements (START -> BEGIN)"
./minised test5.txt "START" "BEGIN"
if [ $? -eq 0 ] && [ -f "test5.txt.replace" ]; then
    make_expected_file "/tmp/expected_5.txt" 'BEGIN middle END
BEGIN
END
BEGINEND
'
    if compare_files "/tmp/expected_5.txt" "test5.txt.replace"; then
        check_pass "Boundary replacements work correctly"
    else
        check_fail "Output mismatch for boundary test"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_5.txt"
        echo "Actual (cat -A):"
        cat -A "test5.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 6: Empty file
echo "Test 6: Empty input file"
./minised empty.txt "test" "replaced"
if [ $? -eq 0 ] && [ -f "empty.txt.replace" ]; then
    if [ ! -s "empty.txt.replace" ]; then
        check_pass "Empty file produces empty output"
    else
        check_fail "Empty file should produce empty output"
        echo "Output content:"
        cat -A empty.txt.replace
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 7: Identity
echo "Test 7: s1 equals s2 (hello -> hello)"
./minised test7.txt "hello" "hello"
if [ $? -eq 0 ] && [ -f "test7.txt.replace" ]; then
    make_expected_file "/tmp/expected_7.txt" 'hello world hello
'
    if compare_files "/tmp/expected_7.txt" "test7.txt.replace"; then
        check_pass "Identity replacement preserves content"
    else
        check_fail "Output mismatch for identity replacement"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_7.txt"
        echo "Actual (cat -A):"
        cat -A "test7.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 8: Not found
echo "Test 8: s1 not found (xyz -> abc)"
./minised test8.txt "xyz" "abc"
if [ $? -eq 0 ] && [ -f "test8.txt.replace" ]; then
    make_expected_file "/tmp/expected_8.txt" 'The quick brown fox
'
    if compare_files "/tmp/expected_8.txt" "test8.txt.replace"; then
        check_pass "No replacement when s1 not found"
    else
        check_fail "Output should be identical when s1 not found"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_8.txt"
        echo "Actual (cat -A):"
        cat -A "test8.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 9: Full content
echo "Test 9: s1 is entire content (replace_me -> DONE)"
./minised test9.txt "replace_me" "DONE"
if [ $? -eq 0 ] && [ -f "test9.txt.replace" ]; then
    make_expected_file "/tmp/expected_9.txt" 'DONE
'
    if compare_files "/tmp/expected_9.txt" "test9.txt.replace"; then
        check_pass "Full-content replacement works"
    else
        check_fail "Output mismatch for full-content replacement"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_9.txt"
        echo "Actual (cat -A):"
        cat -A "test9.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 10: Non-overlapping
echo "Test 10: Non-overlapping (aaaa, aa -> X)"
./minised test10.txt "aa" "X"
if [ $? -eq 0 ] && [ -f "test10.txt.replace" ]; then
    make_expected_file "/tmp/expected_10.txt" 'XX
'
    if compare_files "/tmp/expected_10.txt" "test10.txt.replace"; then
        check_pass "Non-overlapping replacement correct (XX, not XXX)"
    else
        check_fail "Non-overlapping replacement incorrect"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_10.txt"
        echo "Actual (cat -A):"
        cat -A "test10.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 11: Multiline s1
echo "Test 11: Multiline s1 (line one\\nline two -> JOINED)"
./minised test11.txt "line one
line two" "JOINED"
if [ $? -eq 0 ] && [ -f "test11.txt.replace" ]; then
    make_expected_file "/tmp/expected_11.txt" 'JOINED
line three
'
    if compare_files "/tmp/expected_11.txt" "test11.txt.replace"; then
        check_pass "Multiline s1 replacement works"
    else
        check_fail "Output mismatch for multiline s1"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_11.txt"
        echo "Actual (cat -A):"
        cat -A "test11.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 12: Many occurrences
echo "Test 12: Many occurrences (abc -> X, 10 times)"
./minised test12.txt "abc" "X"
if [ $? -eq 0 ] && [ -f "test12.txt.replace" ]; then
    make_expected_file "/tmp/expected_12.txt" 'X X X X X X X X X X
'
    if compare_files "/tmp/expected_12.txt" "test12.txt.replace"; then
        check_pass "Many occurrences replacement works"
    else
        check_fail "Output mismatch for many occurrences"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_12.txt"
        echo "Actual (cat -A):"
        cat -A "test12.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# Test 13: Single char
echo "Test 13: Single char replacement (, -> |)"
./minised test13.txt "," "|"
if [ $? -eq 0 ] && [ -f "test13.txt.replace" ]; then
    make_expected_file "/tmp/expected_13.txt" 'a|b|c|d|e
'
    if compare_files "/tmp/expected_13.txt" "test13.txt.replace"; then
        check_pass "Single character replacement works"
    else
        check_fail "Output mismatch for single char replacement"
        echo "Expected (cat -A):"
        cat -A "/tmp/expected_13.txt"
        echo "Actual (cat -A):"
        cat -A "test13.txt.replace"
    fi
else
    check_fail "Program failed or output file not created"
fi
echo ""

# ============================================
# ERROR HANDLING TESTS
# ============================================

echo -e "${YELLOW}=== ERROR HANDLING TESTS ===${NC}"
echo ""

# Test 14: Too few arguments
echo "Test 14: Too few arguments (2 args)"
./minised test1.txt "hello" 2>/dev/null
if [ $? -ne 0 ]; then
    check_pass "Correctly rejected 2 arguments"
else
    check_fail "Should have rejected 2 arguments"
fi

# Test 15: Too many arguments
echo "Test 15: Too many arguments (5 args)"
./minised test1.txt "hello" "hi" "extra" 2>/dev/null
if [ $? -ne 0 ]; then
    check_pass "Correctly rejected 5 arguments"
else
    check_fail "Should have rejected 5 arguments"
fi

# Test 16: Non-existent file
echo "Test 16: Non-existent file"
./minised nonexistent_file.txt "test" "replaced" 2>/dev/null
if [ $? -ne 0 ]; then
    check_pass "Correctly handled non-existent file"
else
    check_fail "Should have failed on non-existent file"
fi

# Test 17: Empty s1
echo "Test 17: Empty s1"
./minised test1.txt "" "replaced" 2>/dev/null
if [ $? -ne 0 ]; then
    check_pass "Correctly rejected empty s1"
else
    check_fail "Should have rejected empty s1"
fi

# Test 18: Directory as filename
echo "Test 18: Directory as filename"
./minised . "test" "replaced" 2>/dev/null
if [ $? -ne 0 ]; then
    check_pass "Correctly handled directory as filename"
else
    check_fail "Should have failed on directory input"
fi

# Test 19: No arguments
echo "Test 19: No arguments"
./minised 2>/dev/null
if [ $? -ne 0 ]; then
    check_pass "Correctly rejected no arguments"
else
    check_fail "Should have rejected no arguments"
fi

# ============================================
# SUMMARY
# ============================================

echo ""
echo "========================================"
echo "  Results: $PASS passed, $FAIL failed"
echo "========================================"

# Cleanup
rm -f *.replace
rm -f /tmp/expected_*.txt

exit $FAIL
