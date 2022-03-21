/*
** EPITECH PROJECT, 2022
** DLLoader.hpp
** File description:
** template class for making loading several at once possible
*/

#include <vector>
#include <dlfcn.h>
#include <cstddef>

namespace Arcade {

    /*!
    ** \class DLLoader
    ** You are provided with a Template class who will load the libraries automatically for you.
    ** WARNING: Pointers will be deleted by themselves, it is very important to use this template solely
    ** in the Arcade class!!! You will crash if you do use the game pointers after you destroyed
    ** this class.
    **/
    template <typename T>
    class DLLoader
    {
    public:
        DLLoader(void) ///< default constructor
            {
                //empty
            }
        ~DLLoader(void) ///< destructor
            {
                //empty
            }
        void *open(const char *libName) ///< opens the library
        ///< @param libName : filepath to the dynamic library
        ///< @return returns a pointer pointing to the dynamic library given as parameter
            {
                void *ptr = dlopen(libName, RTLD_LAZY);

                this->libPointers.push_back(ptr);
                return (ptr);
            }
        T *getInstance(const char *libName, const char *functionName) ///< returns the corresponding instance of the library
        ///< @param libName : filepath to the dynamic library
        ///< @param functionName : function to be extracted from the library
        ///< @return The initialized class from the library
        ///< @warning You won't have access to the library pointer, so it will close itself at the end of the program
            {
                T *instance = NULL;
                void *ptr = dlopen(libName, RTLD_LAZY);

                if (ptr == NULL)
                    return (NULL);
                this->libPointers.push_back(ptr);
                T *(*iptr)(void) = (T *(*)(void))dlsym(ptr, functionName);
                if (iptr == NULL)
                    return (NULL);
                instance = iptr();
                this->instancePointer.push_back(instance);
                return (instance);
            }
        T *getInstance(void *ptr, const char *functionName) ///< returns the corresponding instance of the library
        ///< @param ptr : pointer pointing to the library
        ///< @param functionName : function to be extracted from the library
        ///< @return The initialized class from the library
            {
                T *instance = NULL;

                if (ptr == NULL)
                    return (NULL);
                T *(*iptr)(void) = (T *(*)(void))dlsym(ptr, functionName);
                if (iptr == NULL)
                    return (NULL);
                instance = iptr();
                this->instancePointer.push_back(instance);
                return (instance);
            }
        void closeLibs(void) ///< closes all libraries
            {
                for (void *ptr : this->libPointers) {
                    if (ptr != NULL)
                        dlclose(ptr);
                }
            }
        void deleteInstances(void) ///< delete all created instances
            {
                for (T *ptr : this->instancePointers)
                    delete ptr;
            }
    private:
        std::vector<void *> libPointers;
        std::vector<T *> instancePointers;
    };

}
