class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashMap<String, Integer> m = new HashMap<>();
        for (String word : wordList) {
            m.put(word, m.getOrDefault(word, 0) + 1);
        }

        Queue<Pair<String,Integer>>q = new LinkedList<>();
        q.add(new Pair<>(beginWord,1));
        m.remove(beginWord);

        // At the worst case there will be all words in wordList (n) in the queue once 
        // for each word -> Length is k average and k*26 after changing characters at all positions
        // O(n*k*k*26 + nlogn) -> multiply k extra for stringbuilder 

        while(!q.isEmpty()){
            Pair<String,Integer>p = q.remove();
            String word = p.getKey();
            int level = p.getValue();

            if(word.equals(endWord)){
                return level;
            }

            for (int i = 0; i < word.length(); i++) {
                String dummyWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (word.charAt(i) == ch) continue;

                    // (k) for copy all chars
                    StringBuilder sb = new StringBuilder(dummyWord);
                    sb.setCharAt(i, ch); // O(1)
                    String str = sb.toString();// O(k)

                    // each word will go only once in queue -> Overall this part is O(nlogn) -> n is words in wordList
                    if (m.containsKey(str)) {
                        q.add(new Pair<>(str, level + 1)); 
                        m.remove(str);
                    }
                }
            }

        }

        return 0;
    }
}