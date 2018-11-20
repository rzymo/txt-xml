# Xml <-> Txt

Parse simple XML structure to TXT and vice versa.
Single row from TXT is enclosed in <row></row> tags and each single value (separated by space) is placed between <col> and </col>, for example:


file.xml:

<root>
  <row>
    <col>1</col>
    <col>2</col>
  </row>
  <row>
    <col>my</col>
    <col>name</col>
    <col>is</col>
    <col>Chris</col>
  </row>
</root>


file.txt:

1 2
my name is Chris

