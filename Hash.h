/*
	Simple string hashing algorithm with low collision rate.

	Created:		2017-12-04 20:29

	Revision:
		Christopher Békési - 2017-12-04 20:29	- Initial
*/

MAINFRAME_API FORCEINLINE__ unsigned long long hashName(const char *s);


template<class _Kty,
	class _Pr = std::less<_Kty>>
	class test_hash
{	// traits class for hash containers
public:
	enum
	{	// parameters for hash table
		bucket_size = 1		// 0 < bucket_size
	};

	test_hash(_Pr _Pred = _Pr())
		: comp(_Pred)
	{	// construct with _Pred comparator
	}

	size_t operator()(const _Kty& _Keyval) const
	{	// hash _Keyval to size_t value by pseudorandomizing transform
		long _Quot = (long)(((size_t)_Keyval ^ 0xdeadbeef) & LONG_MAX);
		ldiv_t _Qrem = _CSTD ldiv(_Quot, 127773);

		_Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
		if (_Qrem.rem < 0)
			_Qrem.rem += LONG_MAX;
		return ((size_t)_Qrem.rem);
	}

	bool operator()(const _Kty& _Keyval1, const _Kty& _Keyval2) const
	{	// test if _Keyval1 ordered before _Keyval2
		return comp(_Keyval1, _Keyval2);
	}

	_Pr comp;	// the comparator object
};