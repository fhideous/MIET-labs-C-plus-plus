template<typename T>

T averge(std::vector<T> vec)
{
	T res = 0;
	int i = 0;

	while (i < vec.size())
	{
		res += vec[i];
		i++;
	}
	res /= vec.size();
	return res;
}
