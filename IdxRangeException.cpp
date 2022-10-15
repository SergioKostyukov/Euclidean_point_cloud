#include "IdxRangeException.h"
#include <sstream>

namespace misc {
    IdxRangeException::IdxRangeException(const unsigned short maxIndex,
                                             const unsigned short givenIndex)
            : Exception(0, "Unknown exception"),
              mMaxIndex(maxIndex), mGivenIndex(givenIndex) {
        std::stringstream errorMsg;
        errorMsg << "Index out of bounds. Max index accepted: ";
        errorMsg << mMaxIndex;
        errorMsg << ", index given: ";
        errorMsg << mGivenIndex;
        errorMsg << ".";
        SetErrorMessage(errorMsg.str());
    }

    unsigned short IdxRangeException::GetMaxIndex() const {
        return mMaxIndex;
    }

    unsigned short IdxRangeException::GetGivenIndex() const {
        return mGivenIndex;
    }
};