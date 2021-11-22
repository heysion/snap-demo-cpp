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

#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>
#include <gtest/gtest.h>

std::map<std::string, int> myMap;
std::vector<std::thread> threadList;

std::thread createThread(const std::string &key) {
    return std::thread([=]() {
        auto const findIter = myMap.find(key);

        if (findIter != myMap.end()) {
            int count = myMap[key];
            std::this_thread::sleep_for(std::chrono::nanoseconds(1));
            myMap[key] = count + 1;
        } else {
            myMap.emplace(key, 1);
        }

        std::cout << "> Result: apple = " << myMap["apple"] << ", potato = " << myMap["potato"] << " - " << key
                  << std::endl;
    });
}

TEST(Thread_vecotr, map01) {
    int maxThreads = 2;

    for (int x = 0; x < maxThreads; x++) {
        threadList.push_back(createThread("potato"));
        threadList.push_back(createThread("apple"));
    }

    for (auto &thread: threadList) {
        thread.join();
    }

    std::cout << "> Result: apple = " << myMap["apple"] << ", potato = " << myMap["potato"] <<
              std::endl;
}