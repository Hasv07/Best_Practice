#### Error Handling
###### *calculateSum can have 3 problems
```
1- A user/programmer may enter a start index greater than the end index.
2- A user/programmer may enter a start or end index out of range.
3- Sum variable may experience overflow due to limitations of the data type in memory.
```
###### *handled by throwing exceptions
<small>1- Invalid Argument Exception</small>
```cpp
   9  if (start > end) {
   10      throw std::invalid_argument("start cannot be greater than end");
   11  }
```
<small> 2- Out of Range Exception</small>
```cpp
  14  if(start < 0 || start > num_arr_size){
  15      throw std::out_of_range("start_idx is out of range index");
  16  }

  18 if(end < 0 || end > num_arr_size){
  19      throw std::out_of_range("start_idx is out of range index");
  20 }
```

<small>3- Overflow Exception</small>
```cpp 
  25 if (num_arr[i] > 0 && sum > INT_MAX - num_arr[i]) {
  26         throw std::overflow_error("integer overflow occurred");
  27 } else if (num_arr[i] < 0 && sum < INT_MIN - num_arr[i]) {
  28         throw std::overflow_error("integer erflow occurred");
  29 }
```

#### Unit Testing

```cpp
Test Cases:
1- int num_arr[] = {1, 2, 3, 4, 5},start=1,end=4 expected -> 9 //basic case
2- int num_arr[] = {1, 2, 3, 4, 5},start=2,end=2 expected -> 0 //empty range
3- int num_arr[] = {1, 2, 3, 4, 5},start=1,end=4 expected -> 15 //full range
4- int num_arr[] = {1, 2, 3, 4, 5},start=3,end=4 expected -> 4 //single element
5- int num_arr[] = {INT_MAX,INT_MAX,INT_MAX},start=0,end=3 expected -> throw overflow exception //overflow handling
6- int num_arr[] = {1, 2, 3, 4, 5},start=3,end=2 expected -> throw invalid_argument exception //invalid argument
7- int num_arr[] = {1, 2, 3, 4, 5},start=3,end=7 expected -> throw out_of_range exception  //out of range



```
#### RUN
```cpp
//runt in terminal
./best_practice
//output
Test Case 1 Passed: Sum is correct.
Test Case 2 Passed: Sum is correct.
Test Case 3 Passed: Sum is correct.
Test Case 4 Passed: Sum is correct.
Test Case 5 Passed: Overflow exception thrown.
Test Case 6 Passed: Invalid argument exception thrown.
Test Case 7 Passed: out_of_range exception thrown.
All tests completed.
```
