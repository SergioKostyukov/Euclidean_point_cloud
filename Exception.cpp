#include "Exception.h"

namespace misc {
    Exception::Exception(unsigned long newErrCode,
                         const std::string &newErrMsg, const Exception *prevLevel)
            : defErrMsg(newErrMsg), errCode(newErrCode) {
        if (prevLevel) {
            unsigned long stackErrCode = prevLevel->GetErrorCode();
            std::string stackErrMsg = prevLevel->GetErrorMessage();
            exStack = prevLevel->exStack;
            exStack.insert(exStack.begin(),
                           std::pair<unsigned long, std::string>(stackErrCode, stackErrMsg)
            );
        }
    }

    Exception::Exception(unsigned long newErrCode, const char *newErrMsg,
                         const Exception *prevLevel)
            : defErrMsg(newErrMsg), errCode(newErrCode) {
        if (prevLevel) {
            unsigned long stackErrCode = prevLevel->GetErrorCode();
            std::string stackErrMsg = prevLevel->GetErrorMessage();
            exStack = prevLevel->exStack;
            exStack.insert(exStack.begin(),
                           std::pair<unsigned long, std::string>(stackErrCode, stackErrMsg)
            );
        }
    }

    Exception::Exception(const Exception &toCopy)
            : defErrMsg(toCopy.defErrMsg), errCode(toCopy.errCode),
              exStack(toCopy.exStack){

    }

    Exception& Exception::operator=(const Exception &toCopy) {
        defErrMsg = toCopy.defErrMsg;
        errCode = toCopy.errCode;
        exStack = toCopy.exStack;

        return *this;
    }

    bool Exception::operator==(const Exception &toCompare) const {
        if (defErrMsg == toCompare.defErrMsg &&
            errCode == toCompare.errCode &&
            exStack == toCompare.exStack)
            return true;

        return false;
    }

    bool Exception::operator!=(const Exception &toCompare) const {
        return !(*this == toCompare);
    }

    const std::string &Exception::GetErrorMessage() const {
        return defErrMsg;
    }

    long Exception::GetErrorCode() const {
        return errCode;
    }

    const Exception::exceptionStack &Exception::GetExceptionStack() const {
        return exStack;
    }

    void Exception::SetErrorMessage(const std::string &errorMessage) {
        defErrMsg = errorMessage;
    }

    void Exception::SetErrorCode(const unsigned long newErrorCode) {
        errCode = newErrorCode;
    }
};