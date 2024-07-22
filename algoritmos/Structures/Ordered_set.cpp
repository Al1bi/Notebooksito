#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

//Nota:
//1. Para un set decreciente usar greater<int>
//2. Para un multiset cambiar less<int> por less_equal<int>
//  2.1 Para borrar un elemento
//  int idx = st.order_of_key(value);
//  st.erase(st.find_by_order(idx));

st.find_by_order(k); // return pointer to the k-th
st.order_of_key(x); // return how many elements are smaller than x
