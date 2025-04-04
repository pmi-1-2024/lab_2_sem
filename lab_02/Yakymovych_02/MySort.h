#ifndef MYSORT_H
#define MYSORT_H

template<typename T, typename Compare>
void mySort(T* begin, T* end, Compare comp) {
    for (T* i = begin; i < end - 1; ++i) {
        for (T* j = i + 1; j < end; ++j) {
            if (comp(*j, *i)) {
                std::swap(*i, *j);
            }
        }
    }
}

#endif
