#  Balanced Brackets

<div class=""><p>
  Write a function that takes in a string made up of brackets (<span>(</span>,
  <span>[</span>, <span>{</span>, <span>)</span>, <span>]</span>, and
  <span>}</span>) and other optional characters. The function should return a
  boolean representing whether the string is balanced with regards to brackets.
</p>
<p>
  A string is said to be balanced if it has as many opening brackets of a
  certain type as it has closing brackets of that type and if no bracket is
  unmatched. Note that an opening bracket can't match a corresponding closing
  bracket that comes before it, and similarly, a closing bracket can't match a
  corresponding opening bracket that comes after it. Also, brackets can't
  overlap each other as in
  <span>[(])</span>.
</p>
<h3>Sample Input</h3>
<pre><span class="CodeEditor-promptParameter">string</span> = "([])(){}(())()()"
</pre>
<h3>Sample Output</h3>
<pre>true <span class="CodeEditor-promptComment">// it's balanced</span>
</pre></div>
