#pragma once

#include <string>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <boost/optional.hpp>
#include <boost/system/error_code.hpp>

template <class T>
using opt = boost::optional<T>;

// shared pointers
template <class T>
using shared_ptr = std::shared_ptr<T>;
template <class T>
using mk_shared = std::make_shared<T>;
template <class T>
using en_shared_this =  std::enable_shared_from_this<T>;

// string
using str = std::string;

// unordered_set
template <class T>
using u_set = std::unordered_set<T>;

// unordered_map
template <class T1, class T2>
using u_map = std::unordered_map<T1, T2>;

// error code
using err_code = boost::system::error_code;
