struct public_key_pair {
    char* e_value;
    char* product;
    char* totient;
};

/**
 * @returns returns the public key pair
 **/
struct public_key_pair generate_publickey();

/**
 * @return returns the private key pair
 * @param public_ekey Public key e value
 * @param totient the totient value
 **/
char* generate_privatekey(char* public_ekey, char* totient);//char public_ekey, char product);

/**
 * Checks if number is prime
 * @returns true if number is prime
 **/ 
bool is_prime();

/**
 * generates a large prime number
 * @return a prime number
 **/ 
int generate_prime();