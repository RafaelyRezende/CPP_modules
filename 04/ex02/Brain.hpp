#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#define MAX_IDEAS 100

class Brain
{
    private:
        std::string _ideas[MAX_IDEAS];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);

        void setIdea(int index, const std::string& new_idea);
        const std::string& getIdea(int index) const;
};
#endif
