
# Hard-coded values for n and e 
n = 5959543795627426174320202010482251983
e = 236234523452345345234523452345243447

# Convert the decimal value of the Radix-64 character to its 6-bit binary value    
def convertToBinary(text):
    bin = 0
    # Use ASCII decimal values to match inputted characters with their Radix-64 decimal value
    if ord(text) >= ord('A') and ord(text) <= ord('Z'):
        bin = ord(text) - ord('A')
    elif ord(text) >= ord('a') and ord(text) <= ord('z'):
        bin = ord(text) - ord('a') + 26
    elif ord(text) >= ord('0') and ord(text) <= ord('9'):
        bin = ord(text) - ord('0') + 52
    elif ord(text) == ord('+'):
        bin = ord(text) - ord('+') + 62
    elif ord(text) == ord('/'):
        bin = ord(text) - ord('/') + 63
        
    # Leading 0's need to be kept because these will all be appended together to form the 120-bit integer
    bin = format(bin, '06b')
    return bin

# modPow function, using given code from lecture
def modPow(base, power, mod):

    if power == 0:
        return 1%mod
        
    if power%2 == 0:
        tmp = modPow(base, power//2, mod)
        return (tmp*tmp)%mod
        
    return (modPow(base, power-1, mod) * base)%mod
    
    
# Read in file, strip newline characters, convert each character to binary, append to 120-bit int, then encrypt 120-bit int
def main():
    
    file = open("text.txt", "r")
    stripped_file = file.read().splitlines()
    for i in range(len(stripped_file)):
        line = ''
        for character in stripped_file[i]:
            tmp = convertToBinary(character)
            line = line + tmp
        #print(line) - To print binary value of line
        line = int(line, 2)
        #print(int(line)) - To print 120-bit integer value of line
        print(modPow(int(line), e, n))
        
    file.close()
    

main()
    

