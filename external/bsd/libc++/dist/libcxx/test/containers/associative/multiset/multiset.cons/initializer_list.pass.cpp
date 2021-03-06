//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <set>

// class multiset

// multiset(initializer_list<value_type> il, const key_compare& comp = key_compare());

#include <set>
#include <cassert>

#include "../../../min_allocator.h"

int main()
{
#ifndef _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
    {
    typedef std::multiset<int> C;
    typedef C::value_type V;
    C m = {1, 2, 3, 4, 5, 6};
    assert(m.size() == 6);
    assert(distance(m.begin(), m.end()) == 6);
    C::const_iterator i = m.cbegin();
    assert(*i == V(1));
    assert(*++i == V(2));
    assert(*++i == V(3));
    assert(*++i == V(4));
    assert(*++i == V(5));
    assert(*++i == V(6));
    }
#endif  // _LIBCPP_HAS_NO_GENERALIZED_INITIALIZERS
#if __cplusplus >= 201103L
    {
    typedef std::multiset<int, std::less<int>, min_allocator<int>> C;
    typedef C::value_type V;
    C m = {1, 2, 3, 4, 5, 6};
    assert(m.size() == 6);
    assert(distance(m.begin(), m.end()) == 6);
    C::const_iterator i = m.cbegin();
    assert(*i == V(1));
    assert(*++i == V(2));
    assert(*++i == V(3));
    assert(*++i == V(4));
    assert(*++i == V(5));
    assert(*++i == V(6));
    }
#if _LIBCPP_STD_VER > 11
    {
    typedef std::multiset<int, std::less<int>, min_allocator<int>> C;
    typedef C::value_type V;
    min_allocator<int> a;
    C m ({1, 2, 3, 4, 5, 6}, a);
    assert(m.size() == 6);
    assert(distance(m.begin(), m.end()) == 6);
    C::const_iterator i = m.cbegin();
    assert(*i == V(1));
    assert(*++i == V(2));
    assert(*++i == V(3));
    assert(*++i == V(4));
    assert(*++i == V(5));
    assert(*++i == V(6));
    assert(m.get_allocator() == a);
    }
#endif
#endif
}
