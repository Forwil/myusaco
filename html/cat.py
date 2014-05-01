#coding:utf-8
import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import requests
import BeautifulSoup
base_url = "http://cerberus.delos.com:790"
url = "http://cerberus.delos.com:790/usacogate?NAME=forwil11&PASSWORD=yu56821423&C=1"
s = requests.Session()
print s.headers
res = s.request("get",url)
soup = BeautifulSoup.BeautifulSoup(res.text)
link = soup.findAll("a")

last = ""

for i in link:
	if i["href"][:4] == "http":
		now_url = i["href"]
	else:
		now_url = base_url + i["href"]
	print now_url
	if i.contents[0] != "Logout":
		html = s.request("get",now_url).text
		print len(html)
		if i.contents[0] != "[ANALYSIS]":
			f = open(i.contents[0] + ".html","w")
		else:
			f = open(last + i.contents[0] + ".html","w")
		f.write(html)
		f.close()
	last = i.contents[0];


