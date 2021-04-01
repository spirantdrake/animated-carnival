# server program
from jsonrpclib.SimpleJSONRPCServer import SimpleJSONRPCServer
import sys
import random
sys.setrecursionlimit(2147483647)


def power(a, n, p):
    # Initialize result
    res = 1

    # Update 'a' if 'a' >= p
    a = a % p

    while n > 0:

        # If n is odd, multiply
        # 'a' with result
        if n % 2:
            res = (res * a) % p
            n = n - 1
        else:
            a = (a ** 2) % p

            # n must be even now
            n = n // 2

    return res % p


def is_prime(num, k):
    # Corner cases
    if num == 1 or num == 4:
        return False
    elif num == 2 or num == 3:
        return True

    # Try k times
    else:
        for i in range(k):

            # Pick a random number
            # in [2..n-2]
            # Above corner cases make
            # sure that n > 4
            a = random.randint(2, num - 2)

            # Fermat's little theorem
            if power(a, num - 1, num) != 1:
                return False

    return True


def main():
    server = SimpleJSONRPCServer(('localhost', 1006))
    server.register_function(is_prime)
    print("Start server")
    server.serve_forever()


if __name__ == '__main__':
    main()

