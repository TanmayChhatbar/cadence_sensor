#ifndef STATS_H
#define STATS_H
class stats {
    public:
        void begin(int n = 10, float var_thresh = 1000);
        void update_stats(float new_value);
        bool is_stationary();
        float get_variance();
        float get_mean();
    private:
        float _mean;
        float _variance;
        float _n;
        float _threshold;
};
#endif  // STATS_H