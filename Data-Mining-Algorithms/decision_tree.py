import numpy as np
from collections import Counter


def entropy(y):
    counts = np.bincount(y)
    probabilities = counts / len(y)
    return -np.sum([p * np.log2(p) for p in probabilities if p > 0])


def split_dataset(X, y, feature_index, threshold):
    left_idx = X[:, feature_index] <= threshold
    right_idx = X[:, feature_index] > threshold
    return X[left_idx], X[right_idx], y[left_idx], y[right_idx]


def best_split(X, y):
    best_gain = -1
    best_feature, best_threshold = None, None
    current_entropy = entropy(y)
    n_features = X.shape[1]

    for feature_index in range(n_features):
        thresholds = np.unique(X[:, feature_index])
        for t in thresholds:
            _, _, y_left, y_right = split_dataset(X, y, feature_index, t)
            if len(y_left) == 0 or len(y_right) == 0:
                continue
            p = len(y_left) / len(y)
            gain = current_entropy - p * \
                entropy(y_left) - (1 - p) * entropy(y_right)
            if gain > best_gain:
                best_gain = gain
                best_feature = feature_index
                best_threshold = t
    return best_feature, best_threshold


class DecisionTreeScratch:
    def __init__(self, depth=0, max_depth=3):
        self.depth = depth
        self.max_depth = max_depth
        self.feature_index = None
        self.threshold = None
        self.left = None
        self.right = None
        self.value = None

    def fit(self, X, y):
        if len(set(y)) == 1 or self.depth >= self.max_depth:
            self.value = Counter(y).most_common(1)[0][0]
            return
        feature, threshold = best_split(X, y)
        if feature is None:
            self.value = Counter(y).most_common(1)[0][0]
            return
        self.feature_index = feature
        self.threshold = threshold

        X_left, X_right, y_left, y_right = split_dataset(
            X, y, feature, threshold)
        self.left = DecisionTreeScratch(
            depth=self.depth + 1, max_depth=self.max_depth)
        self.left.fit(X_left, y_left)
        self.right = DecisionTreeScratch(
            depth=self.depth + 1, max_depth=self.max_depth)
        self.right.fit(X_right, y_right)

    def predict_one(self, x):
        if self.value is not None:
            return self.value
        if x[self.feature_index] <= self.threshold:
            return self.left.predict_one(x)
        else:
            return self.right.predict_one(x)

    def predict(self, X):
        return np.array([self.predict_one(x) for x in X])


if __name__ == "__main__":
    X = np.array([[1, 0], [1, 2], [2, 2], [2, 3], [3, 3], [3, 4]])
    y = np.array([0, 0, 0, 1, 1, 1])

    tree = DecisionTreeScratch(max_depth=2)
    tree.fit(X, y)
    preds = tree.predict(X)
    print("Predictions:", preds)
