/*
 * Copyright (c) 2019-2021. Uniontech Software Ltd. All rights reserved.
 *
 * Author:     Heysion <heysoin@deepin.com>
 *
 * Maintainer: Heysion <heysion@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <vector>

using namespace std;


template<typename T>
void f(std::initializer_list<T> initList) {
    for (const auto &it: initList) {
        cout << it << endl;
    }
}

template<typename Container, typename Index>
auto
Access(Container &&c, Index i)
-> decltype(std::forward<Container>(c)[i]) {
    return std::forward<Container>(c)[i];
}

int main() {
    vector<int> vec_int{1, 2, 3};
    auto s = Access(vec_int, 1);
    cout << s << endl;
    return 0;
}
