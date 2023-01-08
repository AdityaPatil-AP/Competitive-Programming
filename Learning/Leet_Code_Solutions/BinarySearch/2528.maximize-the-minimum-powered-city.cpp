#define ll long long int
class Solution
{
public:
    bool isPossible(ll min_power, const vector<ll> &default_powers, int extra_stations, int r, int num_stations)
    {
        vector<ll> extra_power(num_stations + 1, 0);

        for (int i = 0; i < num_stations; i++)
        {
            extra_power[i] += (i > 0 ? extra_power[i - 1] : 0);

            ll curr_power = extra_power[i] + default_powers[i];
            ll required = max(0ll, min_power - curr_power);
            if (required == 0)
                continue;
            if (required > extra_stations)
                return false;

            extra_stations -= required;

            extra_power[i] += required;
            extra_power[min(num_stations, i + (2 * r) + 1)] -= required;
        }

        return true;
    }

    long long maxPower(vector<int> &stations, int range, int k)
    {
        int n = stations.size();
        // Time Complexity : O(n * log2(m)); m <= 1e10 + 1e9;
        vector<ll> station_powers(n + 1, 0);
        // Prefix Sum.
        for (int i = 0; i < n; i++)
        {
            station_powers[max(0, i - range)] += stations[i];
            station_powers[min(n, i + range + 1)] -= stations[i];
        }

        for (int i = 1; i <= n; i++)
            station_powers[i] += station_powers[i - 1];

        ll l = 0, r = 1e11;
        // The question is can we build k stations in such a way that every city
        // every city has almost x power.
        ll ans = 0;
        while (l <= r)
        {
            ll m = (l + r) >> 1;
            if (isPossible(m, station_powers, k, range, n))
            {
                l = m + 1;
                ans = m;
            }
            else
                r = m - 1;
        }

        return ans;
    }
};