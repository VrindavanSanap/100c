# Dynamic Array Operations

Dynamic operations are actions that can change the structure's size, such as `insert` and `delete`.

## Operations and Complexity

| Operation      | Complexity |
| :------------- | :--------: |
| **Container**  |            |
| Build(X)       |   O(n)     |
| **Static**     |            |
| get_at(i)      |   O(1)     |
| set_at(i, x)   |   O(1)     |
| **Dynamic**    |            |
| insert_first(x)|   O(n)     |
| delete_first() |   O(n)     |
| insert_last(x) |   O(n)     |
| delete_last()  |   O(n)     |
| insert_at(i, x)|   O(n)     |
| delete_at(i)   |   O(n)     |

Dynamic arrays excel at static operations but are less efficient at dynamic operations.