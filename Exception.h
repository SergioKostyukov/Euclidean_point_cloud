#ifndef MAIN_CPP_EXCEPTION_H
#define MAIN_CPP_EXCEPTION_H

#include <vector>
#include <string>

namespace misc {
    //!Common exception class
    /*!This class provides common exception functionality
        with stack of exception history
    */
    class Exception {
    public:

        typedef std::vector<std::pair<unsigned long, std::string> > exceptionStack;

        //!Default constructor
        /*!\param errCode error code of the exception.
            The default value of 0 is an unknown error
            \param errMsg default error message for the given error code
            \param prevLevel exception caught from the previous level.
            NULL if this is the first level of no exception history should be provided
        */
        explicit Exception(unsigned long errCode,
                           const std::string &errMsg = "Unknown error.",
                           const Exception *prevLevel = nullptr);

        //!Construct an exception object
        explicit Exception(unsigned long errCode,
                           const char *errMsg = "Unknown error.",
                           const Exception *prevLevel = nullptr);

        //!Copy constructor
        /*!Create a copy of the given exception
            \param toCopy exception to create a copy of
        */
        Exception(const Exception &toCopy);

        //!Assigment operator
        /*!Assign the given exception to the current one
            \param toCopy exception to create a copy of
        */
        Exception &operator=(const Exception &toCopy);

        //!Equality operator
        /*!Are exceptions equal
            \param toCompare exception to compare the current exception with
            \returns true if exceptions are equal
        */
        bool operator==(const Exception &toCompare) const;

        //!Inequality operator
        /*!Are exceptions equal
            \param toCompare exception to compare the current exception with
            \returns true if exceptions are not equal
        */
        bool operator!=(const Exception &toCompare) const;

        //!Get error message
        /*!Get the default error message of this exception
            \returns reference to a string containing the error message
        */
        const std::string &GetErrorMessage() const;

        //!Get error code
        /*!Get error code of the exception. The error code can be e.g. used to
            provide a language dependent information about the error occurred
            \returns error code
        */
        long GetErrorCode() const;

        //!Get exception stack
        /*!Returns the array of the exceptions occurred on the lower level
            \returns array of exceptions
        */
        const exceptionStack &GetExceptionStack() const;

        //!Set error message
        /*!Set the default error message of this exception
            \param errorMessage the new error message to set
        */
        void SetErrorMessage(const std::string &errorMessage);

        //!Set error code
        /*!Set error code of the exception. The error code can be e.g. used to
            provide a language dependent information about the error occurred
            \param newErrorCode the new error code to set
        */
        void SetErrorCode(unsigned long newErrorCode);

    private:
        std::string defErrMsg;
        unsigned long errCode;
        exceptionStack exStack;
    };
};

#endif //MAIN_CPP_EXCEPTION_H
