# Call by client
from jsonrpclib import Server


def main():
    conn = Server('http://localhost:1006')
    value = int(input("Enter a number: "))
    k = 3
    if conn.is_prime(value, k):
        print(f"The number {value} is prime.")
    else:
        print(f"The number {value} is not prime.")


if __name__ == '__main__':
    main()
