Building
```bash
cd build
USD_INSTALL_ROOT=/usr/local/USD-19.07-python-2.7 cmake ..
make install
```

Debugging
```bash
export TF_DEBUG_OUTPUT_FILE="stderr"
export TF_DEBUG='*'
```


## Summary
This project is a C++ USD resolver plugin. It does nothing but resolve
"/foo" to "/bar".


## To Build
```bash
cd build
USD_INSTALL_ROOT=/usr/local/USD-19.07 cmake ..  # or wherever you've installed USD
make install
```
