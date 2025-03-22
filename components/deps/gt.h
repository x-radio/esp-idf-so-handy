//=============================================================================
//=============================================================================
#ifndef GT_H
#define GT_H
//=============================================================================
#define GT_TICKINSEC            1000UL                      //тиков в секунде
#define GT_TICKINMIN            GT_TICKINSEC*60             //тиков в минуте
#define GT_TICKINHOUR           GT_TICKINSEC*3600           //тиков в часе
#define GT_MSEC(x)              ((x)*GT_TICKINSEC/1000)     //
#define GT_SEC(x)               ((x)*GT_TICKINSEC)          //
#define GT_MIN(x)               ((x)*GT_TICKINMIN)          //
#define GT_HOUR(x)              ((x)*GT_TICKINHOUR)         //
#define GT_PRIME(base, index)   (GT_PRIME_impl(base, index))//вернет ближайшее простое число из таблицы по индексу
//=============================================================================
#ifndef GT_CPP
extern uint64                   global_timer;
#endif
//=============================================================================
void GT_Init(void);
void GT_Poll(void);
//=============================================================================
constexpr std::array<uint32_t, 10> primes_100   = {101, 97, 103, 89, 107, 109, 83, 79, 113, 73};
constexpr std::array<uint32_t, 10> primes_200   = {199, 197, 193, 211, 191, 223, 181, 179, 227, 173};
constexpr std::array<uint32_t, 10> primes_300   = {307, 293, 311, 313, 283, 317, 281, 271, 331, 269};
constexpr std::array<uint32_t, 10> primes_400   = {401, 397, 409, 389, 419, 421, 383, 379, 431, 373};
constexpr std::array<uint32_t, 10> primes_500   = {503, 499, 509, 491, 487, 521, 479, 523, 467, 541};
constexpr std::array<uint32_t, 10> primes_600   = {601, 599, 607, 593, 613, 617, 587, 619, 577, 571};
constexpr std::array<uint32_t, 10> primes_700   = {701, 709, 691, 719, 683, 727, 677, 673, 733, 661};
constexpr std::array<uint32_t, 10> primes_800   = {797, 809, 811, 787, 821, 829, 773, 769, 839, 761};
constexpr std::array<uint32_t, 10> primes_900   = {907, 911, 887, 919, 883, 929, 877, 937, 863, 941};
constexpr std::array<uint32_t, 10> primes_1000  = {1009, 991, 1013, 983, 997, 1019, 977, 1021, 971, 1031};
constexpr std::array<uint32_t, 10> primes_1100  = {1097, 1103, 1093, 1109, 1087, 1117, 1069, 1063, 1123, 1051};
constexpr std::array<uint32_t, 10> primes_1200  = {1201, 1193, 1213, 1187, 1217, 1223, 1181, 1229, 1171, 1231};
constexpr std::array<uint32_t, 10> primes_1300  = {1301, 1303, 1297, 1307, 1291, 1319, 1289, 1321, 1279, 1327};
constexpr std::array<uint32_t, 10> primes_1400  = {1399, 1409, 1423, 1381, 1427, 1373, 1429, 1367, 1433, 1361};
constexpr std::array<uint32_t, 10> primes_1500  = {1499, 1511, 1489, 1487, 1523, 1483, 1481, 1531, 1471, 1543};
constexpr std::array<uint32_t, 10> primes_1600  = {1601, 1597, 1607, 1613, 1609, 1583, 1619, 1579, 1621, 1571};
constexpr std::array<uint32_t, 10> primes_1700  = {1699, 1697, 1709, 1693, 1721, 1723, 1669, 1733, 1667, 1663};
constexpr std::array<uint32_t, 10> primes_1800  = {1801, 1789, 1811, 1787, 1783, 1823, 1777, 1831, 1759, 1753};
constexpr std::array<uint32_t, 10> primes_1900  = {1901, 1907, 1889, 1913, 1879, 1877, 1873, 1931, 1871, 1867};
constexpr std::array<uint32_t, 10> primes_2000  = {1999, 2003, 2011, 1997, 2017, 1993, 2027, 1979, 2029, 1973};
constexpr std::array<uint32_t, 10> primes_2100  = {2111, 2089, 2113, 2087, 2083, 2129, 2081, 2131, 2069, 2063};
constexpr std::array<uint32_t, 10> primes_2200  = {2203, 2207, 2213, 2179, 2221, 2237, 2161, 2239, 2153, 2143};
constexpr std::array<uint32_t, 10> primes_2300  = {2297, 2309, 2311, 2293, 2287, 2273, 2333, 2269, 2339, 2267};
constexpr std::array<uint32_t, 10> primes_2400  = {2399, 2411, 2389, 2417, 2383, 2423, 2377, 2393, 2437, 2371};
constexpr std::array<uint32_t, 10> primes_2500  = {2503, 2521, 2477, 2531, 2473, 2539, 2467, 2543, 2447, 2551};
constexpr std::array<uint32_t, 10> primes_2600  = {2593, 2609, 2617, 2591, 2579, 2621, 2557, 2633, 2549, 2647};
constexpr std::array<uint32_t, 10> primes_2700  = {2699, 2711, 2713, 2689, 2693, 2719, 2677, 2729, 2671, 2663};
constexpr std::array<uint32_t, 10> primes_2800  = {2797, 2801, 2803, 2789, 2819, 2791, 2833, 2777, 2837, 2767};
constexpr std::array<uint32_t, 10> primes_2900  = {2903, 2897, 2909, 2917, 2887, 2927, 2879, 2939, 2861, 2857};
constexpr std::array<uint32_t, 10> primes_3000  = {3001, 2999, 3011, 3019, 2971, 3023, 2969, 3041, 2957, 3049};
constexpr std::array<uint32_t, 10> primes_4000  = {4001, 4003, 4007, 3989, 4013, 4019, 3967, 4021, 3947, 4027};
constexpr std::array<uint32_t, 10> primes_5000  = {4999, 5009, 4993, 5011, 4987, 5021, 4973, 5023, 4969, 5039};
constexpr std::array<uint32_t, 10> primes_6000  = {6007, 6011, 5987, 6029, 5981, 6037, 5953, 6043, 5927, 6047};
constexpr std::array<uint32_t, 10> primes_7000  = {7001, 6997, 7013, 7019, 6991, 7027, 6983, 6977, 7039, 6971};
constexpr std::array<uint32_t, 10> primes_8000  = {7993, 8009, 8011, 8017, 7963, 7949, 8039, 7937, 8053, 7927};
constexpr std::array<uint32_t, 10> primes_9000  = {9001, 9007, 9011, 9013, 8999, 9029, 8971, 9041, 8969, 9043};
constexpr std::array<uint32_t, 10> primes_10000 = {10007, 10009, 10037, 10039, 9973, 9967, 9949, 9923, 10061, 10069};
//=============================================================================
constexpr uint32_t GT_PRIME_impl(uint32_t base, uint32_t index)
{
    constexpr size_t array_size = 10;
    return
        base == 100   ? primes_100  [index % array_size] :
        base == 200   ? primes_200  [index % array_size] :
        base == 300   ? primes_300  [index % array_size] :
        base == 400   ? primes_400  [index % array_size] :
        base == 500   ? primes_500  [index % array_size] :
        base == 600   ? primes_600  [index % array_size] :
        base == 700   ? primes_700  [index % array_size] :
        base == 800   ? primes_800  [index % array_size] :
        base == 900   ? primes_900  [index % array_size] :
        base == 1000  ? primes_1000 [index % array_size] :
        base == 1100  ? primes_1100 [index % array_size] :
        base == 1200  ? primes_1200 [index % array_size] :
        base == 1300  ? primes_1300 [index % array_size] :
        base == 1400  ? primes_1400 [index % array_size] :
        base == 1500  ? primes_1500 [index % array_size] :
        base == 1600  ? primes_1600 [index % array_size] :
        base == 1700  ? primes_1700 [index % array_size] :
        base == 1800  ? primes_1800 [index % array_size] :
        base == 1900  ? primes_1900 [index % array_size] :
        base == 2000  ? primes_2000 [index % array_size] :
        base == 2100  ? primes_2100 [index % array_size] :
        base == 2200  ? primes_2200 [index % array_size] :
        base == 2300  ? primes_2300 [index % array_size] :
        base == 2400  ? primes_2400 [index % array_size] :
        base == 2500  ? primes_2500 [index % array_size] :
        base == 2600  ? primes_2600 [index % array_size] :
        base == 2700  ? primes_2700 [index % array_size] :
        base == 2800  ? primes_2800 [index % array_size] :
        base == 2900  ? primes_2900 [index % array_size] :
        base == 3000  ? primes_3000 [index % array_size] :
        base == 4000  ? primes_4000 [index % array_size] :
        base == 5000  ? primes_5000 [index % array_size] :
        base == 6000  ? primes_6000 [index % array_size] :
        base == 7000  ? primes_7000 [index % array_size] :
        base == 8000  ? primes_8000 [index % array_size] :
        base == 9000  ? primes_9000 [index % array_size] :
        base == 10000 ? primes_10000[index % array_size] :
        GT_MSEC(base);
}
//=============================================================================
#endif
