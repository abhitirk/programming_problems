class PermuteDice {
	public static List<int[]> permute(int totalDice) {
		List<int[]> results = Lists.newLinkedList();
		int[] previousDice = new int[totalDice];
		recursive(totalDice, 0, previousDice, results);
		return results;
	}
	public static void recursive(int totalDice, int currentIndex, int[] previousDice, List<int[]> results) {
		if (currentIndex == totalDice) {
			results.add(previousDice.clone());
			return;
		}
		for (int i = 1; i <= 6; i++) {
			previousDice[currentIndex] = i;
			recursive(totalDice, currentIndex + 1, previousDice, results);
		}
	}
}