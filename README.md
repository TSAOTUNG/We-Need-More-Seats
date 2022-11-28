# We-Need-More-Seats
Description

There are many people buying food at Food Court every day. The seats are limited, so many students can’t find places to sit during the lunch breaks. To know how many seats we need, you must analyze the customer traffic first.

Since the limited seats will influence the number of incoming customers, you might need to create a virtual environment without seating condition. Assume you can cast a spell to remove all furniture and enlarge the ground so that everyone has a space.

For simplicity, you only need to look at the traffic of one day in each testcase. Also, everyone eats their food in the food court (they won’t ask for takeout.) In addition, people go to the food court in groups and the people in the same group buy their food from the same store.

In each testcase, there will be n groups and their information will be given in the input one by one. For any group i, the information will be specified in a line consists of 3 integers and 1 string without whitespaces, including:

The number of people in this group, Pi.
The time the group arrives at, Ai.
The time the group leaves at, Li.
The name of the store the group shops, Si
You need to develop a program to organize the data and it should be able to provide the following information that can be queried by a user:

The time that the Kth earliest group arrives at.
The number of people in the food court at the time T.
The time when there are the most people in the food court and the number of the people in the food court at that time. In the case of multiple possible solutions, provide the solution with earliest time of having maximum traffic.
A list of the names of all the stores that appeared in the data. The names in the list should be distinct. Print them in the lexicographical order and separate them with a space. Here, the order of the characters is based on the ASCII code. The smaller the code of a character is, the higher priority the character has to be sorted in the front.
