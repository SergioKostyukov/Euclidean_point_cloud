#ifndef MAIN_CPP_IDXRANGEEXCEPTION_H
#define MAIN_CPP_IDXRANGEEXCEPTION_H

#include "Exception.h"

namespace misc {
    //!This class represents a index out of range exception.
    class IdxRangeException : public Exception {
    public:

        //!Constructor
        /*!Constructs an exception object with given parameters:
            \param maxIndex const max index
            \param givenIndex const given index
        */
        IdxRangeException(unsigned short maxIndex,
                            unsigned short givenIndex);

        //!The GetMaxIndex function
        /*!The GetMaxIndex function
            \return	const unsigned short
        */
        unsigned short GetMaxIndex() const;

        //!The GetGivenIndex function
        /*!The GetGivenIndex function
            \return	const unsigned short
        */
        unsigned short GetGivenIndex() const;

    protected:
    private:
        unsigned short mMaxIndex;
        unsigned short mGivenIndex;
    };
};

#endif //MAIN_CPP_IDXRANGEEXCEPTION_H
