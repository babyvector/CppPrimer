#ifndef _14_32_STRBLOBMANAGER_HPP_
#define _14_32_STRBLOBMANAGER_HPP_

#include "14_30_constStrBlobPtr.hpp"
class StrBlobManager{
    friend class StrBlobPtr;
public:
    StrBlobManager() = default;
    StrBlobManager(StrBlobPtr&lhs):data(&lhs){};

    StrBlobPtr& operator->();

private:
    shared_ptr<StrBlobPtr> data;
    
};

#endif