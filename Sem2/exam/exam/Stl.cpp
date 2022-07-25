//template<typename InIt, typename Fun>
//Fun for_each(InIt b, InIt e, Fun f) {
//	while (b != e) {
//		f(*b);
//		++b;
//	}
//	return f;
//}
//
//
//template<typename InIt, typename T>
//InIt find(InIt b, InIt e, T t) {
//	while (b != e)
//		if (*b == t)
//			return b;
//	++b;
//	return b;
//}
//
//template<typename InIt, typename
//	Pred>
//	InIt find_if(InIt b, InIt e, Pred p) {
//	while (b != e)
//		if (p(*b))
//			return b;
//	++b;
//	return b;
//}
//
//template<typename InIt1, typename InIt2>
//bool equal(InIt1 b, InIt1 e, InIt2 b1){
//	while (b != e) {
//		if (*b != *b1)
//			return false;
//		++b;
//		++b1;
//	}
//	return true;
//}
//
//template<typename ItIn, typename
//	ItOut>
//	void copy(ItIn b, ItIn e, ItOut b1) {
//	while (b != e) {
//		*b1 = *b;
//		++b;
//		++b1;
//	}
//}
//
//
//template<class InputIt, class OutputIt, class UnaryPredicate>
//OutputIt copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred) {
//	while (first != last) {
//		if (pred(*first))
//			*d_first++ = *first;
//		first++;
//	}
//	return d_first;
//}
//
//template<class InputIt, class OutputIt, class UnaryOperation>
//OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op) {
//	while (first1 != last1) {
//		*d_first++ = unary_op(*first1++);
//	}
//	return d_first;
//}
//
//
//template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
//OutputIt transform(InputIt first1, InputIt last1, InputIt first2, OutputIt d_first, BinaryOperation binary_op)
//{
//	while (first1 != last1) {
//		*d_first++ = binary_op(*first1++, *first2++);
//	}
//	return d_first;
//}