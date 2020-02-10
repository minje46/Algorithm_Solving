### Various Sort

------

## 1. Insertion & Selection sort

- The **main point** of insertion sort is **search and insert.**

  > Search : search the list for a correct position.
  >
  > Insert : Insert new value in correct position directly.

  <img width="293" alt="insertion" src="https://user-images.githubusercontent.com/23169707/46024607-247caf00-c122-11e8-9984-d1aa7588d86e.png">

- Performace 
  $$
  O(n^2)
  $$

- Simple and good for a short list



* The **main point** of selection sort is **search the largest value and swap.**

  <img width="300" alt="selection" src="https://user-images.githubusercontent.com/23169707/46024956-bf758900-c122-11e8-839e-80601f1b2a7a.png">

* Performance
  $$
  O(n^2)
  $$

* Useful for a small list stored in EEPROM or Flash memroy.





------

## 2. Bubble Sort 

- The **main point** of bubble sort is **compare two values  and swap.**

  <img width="300" alt="bubble" src="https://user-images.githubusercontent.com/23169707/46025260-82f65d00-c123-11e8-8be9-a3b5e11f2bfb.png">

- Performance
  $$
  O(n^2)
  $$

- Similar to selection sort though, it is the slowest sort. 





------

## 3. Merge Sort 

- The **main point** of merge sort is **split and merge.**

  > Split : Divide a list successively into two unsorted sub lists.
  >
  > Merge : Merge the two sub lists successively into a single sorted list.

  <img width="581" alt="merge" src="https://user-images.githubusercontent.com/23169707/46024302-73761480-c121-11e8-9080-31fb23308847.png">

- Performace 
  $$
  O(n log2 n)
  $$

- Stable sort

- O(n) storage space





------

## 4. Heap Sort 

- The **main point** of heap sort is **build heap and swap and build heap again.**

  > Build max heap : First, **build a max heap** with original input array.
  >
  > Swap and delete : After built max heap, the **root node is the largest value** so it will **swap with the last leaf node.** Then **delete the last leaf node.**
  >
  > Build max heap again : Last, build a max heap **with reduced array which is deleted the largest value before.**

  <img width="149" alt="heap" src="https://user-images.githubusercontent.com/23169707/46025774-a40b7d80-c124-11e8-8735-7d21f0fbaca9.png">

- Performance
  $$
  O(n log2 n)
  $$

- Small need for storage space.





------

## 5. Counting Sort 

- The **main point** of counting sort is **counting and building an accumulative count.**

  > Counting : Count how many times the value is used.
  >
  > Accumulative count : Building the accumulative count based on count array. Accumulative means the index of new array.

  <img width="432" alt="counting" src="https://user-images.githubusercontent.com/23169707/46582651-4280d280-ca85-11e8-8a81-19ebd3119bc9.png">

- Performance :
  $$
  O(n)
  $$

- Unstable sort.

- The efficiency depends on the input size. Because it should check how many times the value is used.





------

## 6. Radix Sort 

- The **main point** of radix sort is **comparing the digit of value.**

  > Check the max value : Check what **the max value** is in input array because **the itterative** time **depends on the digit of max value.**
  >
  > Compare the digit of value : Compare and sort the value.
  >
  > Change the digit : Change the digit step by step.  `exp = 1; ` `(value / exp)% 10;` `exp *= 10;`
  >
  > Update : The input **value is reset depends on digit** in every pass.

  <img width="298" alt="radix" src="https://user-images.githubusercontent.com/23169707/46582761-47df1c80-ca87-11e8-98a1-aaf0ab9e5174.png">

- Performance : 
  $$
  O(kn)
  $$


  > k : number of digits per key.
  >
  > n : number of keys to sort.

- The queue is essential to store the result of digit's comparison.

- The performnace depends on the size of the keys and choice of the radix(digit, alphabet).

