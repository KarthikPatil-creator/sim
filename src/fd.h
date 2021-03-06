// -*- c++ -*-
/*
 *    Copyright 2020 Google LLC
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        https://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#include <string>

namespace Sim {
class FD
{
public:
    explicit FD(int fd);

    // No copy.
    FD(const FD&) = delete;
    FD& operator=(const FD&) = delete;

    // Move is fine, if done manually.
    FD(FD&&) noexcept;
    FD& operator=(FD&&) = delete; // Just temporarily not implemented.

    ~FD();
    void write(const std::string& s);
    void close();
    [[nodiscard]] std::string read();
    [[nodiscard]] uid_t get_uid() const;
    [[nodiscard]] gid_t get_gid() const;

private:
    int fd_;
};
} // namespace Sim
