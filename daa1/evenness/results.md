# "Fun Activity" Results

## Method
Each algorithm was implemented in and run on Python 3.10.5 (windows).  
For every test, a set amount of random numbers with a specified max size is generated, 
and the total run-time for each algorithm to test every element in this set is measured.  
Then this time is divided by the number of elements to obtain the average run time for each algorithm.

## Conclusions

For smaller integers (word size), the modulus operator is the
fastest check for evenness, with the bitwise AND being the second fastest.

For integers that take up more space than normal (longs and arbitrary size integers),
the bitwise AND operator is faster. Bitwise OR was however still slower than the modulo operation.

The power of 7 algorithm was the slowest, after repeated subtraction.

The test data that will follow shows a general trend with other algorithms
that can be used to determine their relative performance.

## Test Data

### Test Case 1

100,000 test cases  
Maximum integer size 1000

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |       99.956 ns |
| Modulus              |       79.985 ns |
| Repeated Subtraction |     9880.423 ns |
| Power of -1          |      289.977 ns |
| Last digit check     |      109.995 ns |
| Sin check            |      220.013 ns |
| GCD                  |      130.002 ns |
| LCM                  |      189.987 ns |
| Bitwise OR           |      109.614 ns |
| Prime factorization  |     1990.015 ns |
| Power of 7           |    29840.523 ns |

Total run time 4.294049s

### Test Case 2

50,000 test cases  
Maximum integer size 1e+4

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |       99.996 ns |
| Modulus              |      100.096 ns |
| Repeated Subtraction |   118440.118 ns |
| Power of -1          |      379.908 ns |
| Last digit check     |      139.974 ns |
| Sin check            |       280.07 ns |
| GCD                  |      159.724 ns |
| LCM                  |      240.078 ns |
| Bitwise OR           |      179.998 ns |
| Prime factorization  |     4919.132 ns |
| Power of 7           |    348320.82 ns |

Total run time 23.6629957s

### Test Case 3

10,000 test cases  
Maximum integer size 1e+5

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |        99.75 ns |
| Modulus              |       100.38 ns |
| Repeated Subtraction |  1121.20 **μs** |
| Power of -1          |       300.38 ns |
| Last digit check     |       199.68 ns |
| Sin check            |       200.27 ns |
| GCD                  |        199.9 ns |
| LCM                  |       199.75 ns |
| Bitwise OR           |         99.7 ns |
| Prime factorization  |      7296.21 ns |
| Power of 7           |  3408.20 **μs** |

Total run time 45.3809589s

### Test Case 4

100,000 test cases  
Maximum integer size 1e+8

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |      110.001 ns |
| Modulus              |      100.013 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |      470.046 ns |
| Last digit check     |      139.986 ns |
| Sin check            |      289.994 ns |
| GCD                  |      150.002 ns |
| LCM                  |      240.003 ns |
| Bitwise OR           |      139.998 ns |
| Prime factorization  |   119449.988 ns |
| Power of 7           |        Too Slow |

Total run time 12.1090031s

### Test Case 5

1,000,000 test cases  
Maximum integer size 1e+10

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |      98.0004 ns |
| Modulus              |      104.996 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |     500.0016 ns |
| Last digit check     |     129.0063 ns |
| Sin check            |     260.9921 ns |
| GCD                  |     150.9998 ns |
| LCM                  |     257.0014 ns |
| Bitwise OR           |     135.9553 ns |
| Prime factorization  |        Too Slow |
| Power of 7           |        Too Slow |

Total run time 1.6389566s

### Test Case 6

1,000,000 test cases  
Maximum integer size 1e+12

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |      96.9978 ns |
| Modulus              |     106.9994 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |     587.0031 ns |
| Last digit check     |     124.9566 ns |
| Sin check            |     260.0411 ns |
| GCD                  |     149.9602 ns |
| LCM                  |     253.9993 ns |
| Bitwise OR           |     127.0449 ns |
| Prime factorization  |        Too Slow |
| Power of 7           |        Too Slow |

Total run time 1.7070024s

### Test Case 7

1,000,000 test cases  
Maximum integer size 1e+14

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |     124.9938 ns |
| Modulus              |     130.9973 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |     711.0043 ns |
| Last digit check     |     145.0021 ns |
| Sin check            |     303.9521 ns |
| GCD                  |     177.0004 ns |
| LCM                  |     292.0447 ns |
| Bitwise OR           |     142.9992 ns |
| Prime factorization  |        Too Slow |
| Power of 7           |        Too Slow |

Total run time 2.0279939s

### Test Case 8

1,000,000 test cases  
Maximum integer size 1e+16

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |     112.9953 ns |
| Modulus              |     124.9978 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |     759.0008 ns |
| Last digit check     |     147.9599 ns |
| Sin check            |     315.0038 ns |
| GCD                  |     176.9959 ns |
| LCM                  |     294.0484 ns |
| Bitwise OR           |     142.9973 ns |
| Prime factorization  |        Too Slow |
| Power of 7           |        Too Slow |

Total run time 2.0739992s

### Test Case 9

1,000,000 test cases  
Maximum integer size 1e+18

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |     114.0034 ns |
| Modulus              |     125.9816 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |     787.0175 ns |
| Last digit check     |     142.9982 ns |
| Sin check            |      313.002 ns |
| GCD                  |      177.998 ns |
| LCM                  |     298.0008 ns |
| Bitwise OR           |      141.001 ns |
| Prime factorization  |        Too Slow |
| Power of 7           |        Too Slow |

Total run time 2.1000025s

### Test Case 10

1,000,000 test cases  
Maximum integer size 1e+20

| Algorithm            | Average Runtime |
|----------------------|----------------:|
| Bitwise AND          |     115.9981 ns |
| Modulus              |     134.9945 ns |
| Repeated Subtraction |        Too Slow |
| Power of -1          |     982.0076 ns |
| Last digit check     |     148.9977 ns |
| Sin check            |     314.9585 ns |
| GCD                  |     206.0007 ns |
| LCM                  |     323.9995 ns |
| Bitwise OR           |     145.0417 ns |
| Prime factorization  |        Too Slow |
| Power of 7           |        Too Slow |

Total run time 2.3719983s

### Test Case 11

10,000,000 test cases  
Maximum integer size 1e+5

| Algorithm   | Average Runtime |
|-------------|----------------:|
| Bitwise AND |      102.047 ns |
| Modulus     |     85.04181 ns |
| Bitwise OR  |    115.09855 ns |

Total run time 3.0218736s

### Test Case 12

10,000,000 test cases
Maximum integer size 1e+10

| Algorithm   | Average Runtime |
|-------------|----------------:|
| Bitwise AND |     94.00438 ns |
| Modulus     |    111.44065 ns |
| Bitwise OR  |    126.77595 ns |

Total run time 3.3222098s
