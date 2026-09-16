<h2><a href="https://leetcode.com/problems/range-addition">370. Range Addition</a></h2><h3>Medium</h3><hr><p>Assume you have an array of length <code>length</code> initialized with all <code>0</code>'s and are given an integer array <code>updates</code>.</p>

<p>Each update is represented as a pair of integers <code>[startIndex, endIndex, inc]</code>. You should increment each element of the array from <code>startIndex</code> to <code>endIndex</code> (inclusive) by <code>inc</code>.</p>

<p>Return the modified array after all updates are applied.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]
<strong>Output:</strong> [-2,0,3,5,3]
</pre>

<p><strong>Explanation:</strong></p>
<ul>
	<li>Initial array: <code>[0,0,0,0,0]</code></li>
	<li>After <code>[1,3,2]</code>: <code>[0,2,2,2,0]</code></li>
	<li>After <code>[2,4,3]</code>: <code>[0,2,5,5,3]</code></li>
	<li>After <code>[0,2,-2]</code>: <code>[-2,0,3,5,3]</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= updates.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= startIndex &lt;= endIndex &lt; length</code></li>
	<li><code>-10<sup>3</sup> &lt;= inc &lt;= 10<sup>3</sup></code></li>
</ul>
