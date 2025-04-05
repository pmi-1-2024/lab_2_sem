#pragma once

template <typename T>
struct Link {
    T data;
    Link<T>* next;

    Link(const T& data) : data(data), next(nullptr) {}
};
