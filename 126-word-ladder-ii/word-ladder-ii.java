class Solution {
    private List<List<String>> result;
    private Map<String, Set<String>> predecessors;

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        result = new ArrayList<>();
        
        Set<String> wordSet = new HashSet<>(wordList);

        if(!wordSet.contains(endWord)) {
            return result;
        }

        wordSet.remove(beginWord);

        Map<String, Integer> distanceMap = new HashMap<>();
        distanceMap.put(beginWord, 0);

        predecessors = new HashMap<>();

        Queue<String> queue = new ArrayDeque<>();
        queue.offer(beginWord);

        boolean targetFound = false;
        int currentStep = 0;

        while (!queue.isEmpty() && !targetFound) {
            currentStep++;
            int levelSize = queue.size();

            for (int i = 0; i < levelSize; i++) {
                String currentWord = queue.poll();
                char[] wordChars = currentWord.toCharArray();

                for (int charIndex = 0; charIndex < wordChars.length; charIndex++) {
                    char originalChar = wordChars[charIndex];

                    for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                        wordChars[charIndex] = newChar;
                        String transformedWord = new String(wordChars);

                        if (distanceMap.getOrDefault(transformedWord, 0) == currentStep) {
                            predecessors.get(transformedWord).add(currentWord);
                        }

                        if (!wordSet.contains(transformedWord)) {
                            continue;
                        }

                        predecessors.computeIfAbsent(transformedWord, key -> new HashSet<>())
                                    .add(currentWord);

                        wordSet.remove(transformedWord);
                        queue.offer(transformedWord);
                        distanceMap.put(transformedWord, currentStep);

                        if (endWord.equals(transformedWord)) {
                            targetFound = true;
                        }
                    }

                    wordChars[charIndex] = originalChar;
                }
            }
        }

        if (targetFound) {
            Deque<String> currentPath = new ArrayDeque<>();
            currentPath.add(endWord);
            buildPaths(currentPath, beginWord, endWord);
        }

        return result;
    }

    private void buildPaths(Deque<String> currentPath, String beginWord, String currentWord) {
        if (currentWord.equals(beginWord)) {
            result.add(new ArrayList<>(currentPath));
            return;
        }

        for (String predecessor : predecessors.get(currentWord)) {
            currentPath.addFirst(predecessor);
            buildPaths(currentPath, beginWord, predecessor);
            currentPath.removeFirst(); 
        }
    }
}