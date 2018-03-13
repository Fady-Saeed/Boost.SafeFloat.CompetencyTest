# Boost.SafeFloat.CompetencyTest
## Programming competency test

Define a user defined literal assignable to float that fails compilation when the value provided cannot be expressed as an positive integer power of 0.5 (e.g. 0.5, 0.25, 0.125).

Provide a function receiving an integer (X) and a tuple (std::tuple<type1, type2, type3…>) into a tuple of vectors (std::tuple<std::vector,std::vector, std::vector, …> where each vector has X elements of each originally received in each tuple_element. E.g. for X=2 and the tuple {1, 1.0, ‘a’} , the result type is std::tuple<std::vector, std::vector, std::vector> and the values are: {{1, 1},{1.0, 1.0},{‘a’, ‘a’}}

Provide a template function “get_vector”, similar to std::get, that given the type X as parameter, returns editable access to the vector of type X in a tuple of vectors.
