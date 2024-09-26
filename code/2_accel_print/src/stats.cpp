#include "stats.h"

void stats::begin(int n, float var_thresh) {
    _mean = 0;
    _variance = 0;
    _n = n;
    _threshold = var_thresh;
}

void stats::update_stats(float new_value) {
    _mean = _mean + (new_value - _mean) / (_n + 1);
    _variance = (_n * _variance + (new_value - _mean) * (new_value - _mean)) / (_n + 1);
}

bool stats::is_stationary() {
    return _variance < _threshold;
}

float stats::get_variance() {
    return _variance;
}

float stats::get_mean() {
    return _mean;
}
