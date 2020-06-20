#include "14_32_StrBlobManager.hpp"

StrBlobPtr& StrBlobManager::operator->(){
    return *data.get();
}