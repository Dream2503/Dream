# Q5. Write a shell script to add, subtract and multiply two given numbers passed as command line arguments.

#!/bin/bash
echo "Sum: $(($1 + $2))"
echo "Difference: $(($1 - $2))"
echo "Product: $(($1 * $2))"
