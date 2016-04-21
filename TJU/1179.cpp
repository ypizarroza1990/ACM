#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define sqr(x)((x)*(x))
using namespace std;
typedef long long i64;
const int MAX=1e6;
class BigInteger
{
	static const int _capacity = 10000, _bits = 28;
	static const unsigned long long _mod = 1ULL << _bits;
	unsigned int _buffer[_capacity];
	int _size;

	void _set(const BigInteger & right)
	{
		memcpy(_buffer, right._buffer, sizeof(_buffer));
		_size = right._size;
	}

	void _set(int right)
	{
		if(right) _buffer[_capacity-1] = right, _size = 1;
		else _size = 0;
	}

	void _set(const char * psz)
	{
		int length = strlen(psz);
		int cnt = length/12 + 1;
		unsigned long long * tmp = new unsigned long long[cnt];

		int k = 0;
		{
			unsigned long long t = 0;
			for(int j = 0; j < length%12; ++j) t = t*10 + (psz[k++] - '0');
			tmp[0] = t;
		}

		for(int i = 1; i < cnt; ++i)

		{

			unsigned long long t = 0;
			for(int j = 0; j < 12; ++j)	t = t*10 + (psz[k++] - '0');
			tmp[i] = t;
		}

		_size = 0;
		int j = 0, g = 0;
		while(true)
		{
			while(j < cnt && tmp[j] == 0) ++j;
			if(j == cnt) break;
			unsigned long long rem = 0, mod = 1ULL << (_bits / 2);
			for(int i = j; i < cnt; ++i)
			{
				unsigned long long t = tmp[i] + rem * 1000000000000ULL;
				tmp[i] = t / mod, rem = t % mod;
			}
			if(g & 1) _buffer[_capacity - _size] |= static_cast<unsigned int>(rem << (_bits / 2));
			else _buffer[_capacity - ++_size] = static_cast<unsigned int>(rem);
			++g;
		}
		delete tmp;
	}

	static BigInteger _max_square_root()
	{
		BigInteger ret;

		int size = _capacity / 2 - 1;
		for(int i = 0; i < size; ++i) ret._buffer[i] = _mod - 1;
		ret._size = size;

		return ret;
	}

	unsigned int _divide(unsigned int right)
	{
		unsigned long long rem = 0;
		for(int i = _capacity - _size; i < _capacity; ++i)
		{
			unsigned long long t = _buffer[i] + rem * _mod;
			_buffer[i] = static_cast<unsigned int>(t / right), rem = t % right;
		}
		while(_size > 0 && _buffer[_capacity - _size] == 0) --_size;
		return static_cast<unsigned int>(rem);
	}

public:
	BigInteger(): _size(0){}
	BigInteger(const BigInteger & right) { _set(right); }
	BigInteger(unsigned int right) { _set(right); }
	BigInteger(const char * psz) { _set(psz); }

	BigInteger & operator = (const BigInteger & right) { _set(right); return * this; }

	BigInteger & operator = (const char * right) { _set(right);	return * this; }

	friend BigInteger operator + (const BigInteger & left, const BigInteger & right)
	{
		BigInteger out = left;
		return out += right;
	}

	BigInteger & operator += (const BigInteger & right)
																   {
		unsigned long long t = 0;
		int i = _capacity - 1, _i = 0, _is = _size, _j = 0, _js = right._size;
		for(int j = _capacity - 1; i >= 0 && (t > 0 || _j < _js); --i, --j, ++_i, ++_j, t /= _mod)
		{
			if(_i < _is) t += _buffer[i];
			if(_j < _js) t += right._buffer[j];
			_buffer[i] = t % _mod;
		}
		_size = max(_size, _capacity - i - 1);
		return * this;
																   }

	friend BigInteger operator - (const BigInteger & left, const BigInteger & right)
	{
		BigInteger out = left;
		return out -= right;
	}

	BigInteger & operator -= (const BigInteger & right)
																   {
		unsigned long long t = 0;
		int i = _capacity - 1, _i = 0, _is = _size, _j = 0, _js = right._size;
		for(int j = _capacity - 1; _i < _is && (t > 0 || _j < _js); --i, --j, _i++, ++_j)
		{
			if(_j < _js) t += right._buffer[i];
			if(_buffer[i] < t)  _buffer[i] = static_cast<unsigned int>(_mod + _buffer[i] - t), t = 1;
			else _buffer[i] -= static_cast<unsigned int>(t), t = 0;
		}
		while(_size > 0 && _buffer[_capacity - _size] == 0) --_size;
		return * this;
																   }

	friend BigInteger operator / (const BigInteger & left, unsigned int right)
																   {
		BigInteger out = left;
		out._divide(right);
		return out;
																   }

	friend unsigned int operator % (const BigInteger & left, unsigned int right)
																   {
		BigInteger out = left;
		return out._divide(right);
																   }

	friend BigInteger operator * (const BigInteger & left, const BigInteger & right)
																   {
		BigInteger out;

		unsigned long long t = 0;
		int c = BigInteger::_capacity, ls = left._size, rs = right._size, l = min(c, ls + rs + 1);
		for(int k = 0; k < l; ++k, t /= BigInteger::_mod)
		{
			for(int j = max(max(0, k - c + 1), k + 1 - ls); j <= k && j < rs; ++j)
				t += 1ULL * left._buffer[c - (k - j) - 1] * right._buffer[c - j - 1];
			out._buffer[c - k - 1] = static_cast<unsigned int>(t % BigInteger::_mod);
		}

		if(t) out._buffer[c - l - 1] = static_cast<unsigned int>(t);
		out._size = l;
		while(out._size > 0 && out._buffer[c - out._size] == 0) --out._size;
		return out;
																   }

	friend BigInteger operator % (const BigInteger & left, const BigInteger & right)
																   {
		return left - (left / right) * right;
																   }

	friend BigInteger operator / (const BigInteger & left, const BigInteger & right)
																   {
		BigInteger low, high = left;
		while(low < high)
		{
			BigInteger mid = (++(high + low)) >> 1;
			if(mid * right <= left) low = mid;
			else high = --mid;
		}
		return low;
																   }

	BigInteger & operator *= (const BigInteger & right)
																   {
		* this = * this * right;
		return * this;
																   }

	BigInteger & operator /= (const BigInteger & right)
																   {
		* this = * this / right;
		return * this;
																   }

	BigInteger & operator %= (const BigInteger & right)
																   {
		* this = * this % right;
		return * this;
																   }

	BigInteger & operator >>= (int right)
																   {
		if(!_size) return * this;
		unsigned int * begin = _buffer + (_capacity - _size),
				* end = _buffer + _capacity,
				rem = 0, mask = (1 << right) - 1, shift = _bits - right;

		if(* begin <= mask) --_size;

		while(begin != end)
		{
			unsigned int t = (* begin & mask) << shift;
			* begin = (* begin >> right) | rem, rem = t, ++begin;
		}

		return * this;
																   }

	friend BigInteger operator >> (const BigInteger & left, int right)
	{
		return BigInteger(left) >>= right;
	}

	BigInteger & operator += (unsigned int right)\
			{
		unsigned long long t = right;
		int e = _capacity - _size;
		for(int i = _capacity - 1; i >= e && t > 0; --i, t /= _mod)
			_buffer[i] = (t += _buffer[i]) % _mod;

		if(t && e > 0) _buffer[e - 1] = static_cast<unsigned int>(t), ++_size;
		return * this;
			}

	BigInteger & operator -= (unsigned int right)
																   {
		unsigned int t = right;
		int e = _capacity - _size;
		for(int i = _capacity - 1; i >= e && t > 0; --i)
			if(_buffer[i] < t)	_buffer[i] = static_cast<unsigned int>(_mod - t), t = 1;
			else _buffer[i] -= t, t = 0;

		if(!_buffer[e]) --_size;
		return * this;
																   }

	BigInteger & operator ++ () { return * this += 1; }
	BigInteger & operator -- () { return * this -= 1; }

	friend bool operator == (const BigInteger & left, const BigInteger & right)
																   {
		if(left._size != right._size) return false;
		return memcmp(
				left._buffer + (BigInteger::_capacity - left._size),
				right._buffer + (BigInteger::_capacity - right._size),
				sizeof(int) * left._size) == 0;
																   }

	friend bool operator != (const BigInteger & left, const BigInteger & right)
																   {
		return !(left == right);
																   }

	friend bool operator < (const BigInteger & left, const BigInteger & right)
	{
		if(left._size != right._size) return left._size < right._size;
		for(int i = BigInteger::_capacity - left._size; i < BigInteger::_capacity; ++i)
			if(left._buffer[i] != right._buffer[i])
				return left._buffer[i] < right._buffer[i];
		return false;
	}

	friend bool operator <= (const BigInteger & left, const BigInteger & right)
																   {
		return !(left > right);
																   }

	friend bool operator > (const BigInteger & left, const BigInteger & right)
	{
		return right < left;
	}

	friend bool operator >= (const BigInteger & left, const BigInteger & right)
																   {
		return !(left < right);
																   }

	operator void * () const { return (void *) (_size > 0 ? 1 : 0); }

	bool operator !() const { return _size == 0;	}

	char * ToString(char * out) const
	{
		if(!* this)
		{
			out[0] = '0', out[1] = 0;
			return out;
		}

		int size = 0;
		{
			BigInteger t = * this;

			for(;;)
			{
				unsigned int r = t._divide(1000000000U);
				if(t) size += 9;
				else { do ++size; while(r /= 10);	break; }
			}
		}

		out[size--] = 0;

		{
			BigInteger t = * this;
			for(;;)
			{
				unsigned int r = t._divide(1000000000U);
				if(t) for(int i = 0; i < 9; ++i, r /= 10)	out[size--] = r % 10 + '0';
				else { do	out[size--] = r % 10 + '0';	while(r /= 10);	break; }
			}
		}
		return out;
	}
};
int cas;
BigInteger arr[155];
BigInteger two=2;
BigInteger catalan(int n){
	if(n==0)
		return arr[0]=1;
	if(arr[n])
		return arr[n];
	else{
		return arr[n]=(two*(two*n-1)*catalan(n-1))/(n+1);
	}
}
void init(){
	arr[10]=BigInteger("16796");
	arr[20]=BigInteger("6564120420");
	arr[30]=BigInteger("3814986502092304");
	arr[40]=BigInteger("2622127042276492108820");
	arr[50]=BigInteger("1978261657756160653623774456");
	arr[60]=BigInteger("1583850964596120042686772779038896");
	arr[70]=BigInteger("1321422108420282270489942177190229544600");
	arr[80]=BigInteger("1136359577947336271931632877004667456667613940");
	arr[90]=BigInteger("1000134600800354781929399250536541864362461089950800");
	arr[100]=BigInteger("896519947090131496687170070074100632420837521538745909320");
	arr[110]=BigInteger("815663960219058384462569194343901173113117297781505394610791520");
	arr[120]=BigInteger("751269297881058917464501210451062751843240026086509499359064493663600");
	arr[130]=BigInteger("699138751524213124094312216825551629561424593205010237977696200916445964684");
	arr[140]=BigInteger("656376399024616169349253607753345435388942038466586811952779656067170646392272840");
	arr[150]=BigInteger("620925183926009621146978506218967449531342090729015621989883130549504437230725772687824");

}
char Z[100];
int main(){
	init();
	while(scanf("%d",&cas),cas>0){
		printf("%s\n",catalan(cas).ToString(Z));

	}
}


