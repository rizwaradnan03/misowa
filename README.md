STEP FOR MAKING RENDER OF STUFF
1. make a vertex of array (cartesian point)
2. make the gpu's rules to read the vertex using VAO
3. upload to the gpu using VBO / EBO
4. "shader" as the main reason for render di vertex & fragment
5. draw the call for the gpu reads those thing

BUILD STEP
1. cmake -G Ninja ..
2. cmake --build .
3. cpack