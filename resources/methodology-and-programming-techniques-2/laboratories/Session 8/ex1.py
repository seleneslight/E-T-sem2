word = "apple"
N = len(word)
reverse_word = ""
for x in range(N):
    char = word[N-x-1]
    reverse_word += char
    print(char)
print(reverse_word)