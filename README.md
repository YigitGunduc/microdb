# MicroDB

MicroDB is an open-source key-value store written in C.

## Installation

clone the git repo

```bash
git clone https://github.com/YigitGunduc/microdb.git
```

## Methods

* ```create_db``` args: None. Description: creates and return a new DB instance

* ```set``` args: DB instance, key, value. Description: sets the given key to the given value.
adds to the end of the DB

* ```sSet``` args: DB instance, key, value. Description: sets the given key to the given value. adds to the 
beginning of the DB much faster than ```set```

* ```get``` args: DB instance, key. Description: returns value associated with the key

* ```update``` args: DB instance, key, value. Description: updates the key with given new value

* ```del``` args: DB instance, key. Description: deletes the value and key of the given key.

* ```length``` args: DB instance. Description: returns number of elements in the DB

* ```freedb``` args: DB instance. Description: frees the memory addresses that DB holds

* ```listAll``` args: DB instance. Description: displays all the elements in DB with a table



## BENCHMARKS
 - 10000000(10M) querres(reads) in 0.06250 seconds

 - 625000(625K) queries(reads) per second

 - 10000000(10M) queries(write) in 0.359358 seconds

 - 3593700(3.6M) queries(write) per second


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)