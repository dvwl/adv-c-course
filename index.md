# Data, AI, and ML Fundamentals Exercises

These hands-on exercises are designed to support training content.

{% assign labs = site.pages | where_exp:"page", "page.url contains '/modules'" %}
| Exercises |
| ------- | 
{% for activity in labs  %}| [{{ activity.lab.title }}]({{ site.github.url }}{{ activity.url }}) |
{% endfor %}
