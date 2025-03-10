class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            int min_valid_value = -1;
            deque<int> consonant_positions;
            consonant_positions.push_back(-1);
            array<int, 21> last_vowel;
            fill(last_vowel.begin(), last_vowel.end(), -1);
            long long valid_substrings = 0;

            for (int it = 0; it < word.size(); it++) {
                if ((0x208222 >> (word[it] & 0x1f)) & 1) {
                    last_vowel[word[it] - 'a'] = it;

                } else {
                    consonant_positions.push_back(it);
                    if (consonant_positions.size() - 1 > k) {
                        consonant_positions.pop_front();
                    }
                }
                if (consonant_positions.size() - 1 >= k &&
                    last_vowel[0] > consonant_positions.front() &&
                    last_vowel[4] > consonant_positions.front() &&
                    last_vowel[8] > consonant_positions.front() &&
                    last_vowel[14] > consonant_positions.front() &&
                    last_vowel[20] > consonant_positions.front()) {
                    if (k > 0) {
                        min_valid_value = consonant_positions[1];
                    } else {
                        min_valid_value = it;
                    }

                    min_valid_value = min(min_valid_value, last_vowel[0]);
                    min_valid_value = min(min_valid_value, last_vowel[4]);
                    min_valid_value = min(min_valid_value, last_vowel[8]);
                    min_valid_value = min(min_valid_value, last_vowel[14]);
                    min_valid_value = min(min_valid_value, last_vowel[20]);
                    valid_substrings +=
                        (min_valid_value - consonant_positions.front());
                }
            }
            return valid_substrings;
        }

        long long countOfSubstrings_faster(string word, int k) {
            const char a = 'a' - 'a', e = 'e' - 'a', i = 'i' - 'a', o = 'o' - 'a',
                       u = 'u' - 'a';
            int invalid_consonant = 0;
            int min_valid_value = -1;
            vector<int> consonant_positions = {-1};
            array<int, 22> last_vowel;
            fill(last_vowel.begin(), last_vowel.end(), -1);
            long long valid_substrings = 0;

            for (int it = 0; it < word.size(); it++) {
                if ((0x208222 >> (word[it] & 0x1f)) & 1) {
                    last_vowel[word[it] - 'a'] = it;

                } else {
                    consonant_positions.push_back(it);
                    if (consonant_positions.size() - 1 > k) {
                        invalid_consonant++;
                    }
                }
                if (consonant_positions.size() - 1 >= k &&
                    last_vowel[a] > consonant_positions[invalid_consonant] &&
                    last_vowel[e] > consonant_positions[invalid_consonant] &&
                    last_vowel[i] > consonant_positions[invalid_consonant] &&
                    last_vowel[o] > consonant_positions[invalid_consonant] &&
                    last_vowel[u] > consonant_positions[invalid_consonant]) {
                    if (k > 0) {
                        min_valid_value =
                            consonant_positions[invalid_consonant + 1];
                    } else {
                        min_valid_value = it;
                    }

                    min_valid_value = min(min_valid_value, last_vowel[a]);
                    min_valid_value = min(min_valid_value, last_vowel[e]);
                    min_valid_value = min(min_valid_value, last_vowel[i]);
                    min_valid_value = min(min_valid_value, last_vowel[o]);
                    min_valid_value = min(min_valid_value, last_vowel[u]);
                    valid_substrings +=
                        (min_valid_value - consonant_positions[invalid_consonant]);
                }
            }
            return valid_substrings;
        }
    };