def main():
    products = ["mobile","mouse","moneypot","monitor","mousepad"]
    searchWord = "mouse"
    print(sol(products, searchWord))
    return

def sol(products, searchWord):
    output = []
    products.sort()
    match_counts = []
    s_len = len(searchWord)

    for word in products:
        m_len = 0
        w_len = len(word)
        c_len = min(s_len, w_len)
        for i in range(c_len):
            if word[i] != searchWord[i]:
                break
            m_len += 1

        match_counts.append(m_len)

    for sub_len in range(s_len):
        sub_output = []
        count = 0
        for i, m_len in enumerate(match_counts):
            if m_len >= sub_len+1:
                if count > 2:
                    break
                sub_output.append(products[i])
                count += 1
        output.append(sub_output)
                
    return output

if __name__ == "__main__":
    main()
