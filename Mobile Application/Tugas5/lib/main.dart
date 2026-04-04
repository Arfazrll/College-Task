import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Q2',
      theme: ThemeData(
        primarySwatch: Colors.green,
      ),
      home: const MyHomePage(title: 'AP 3'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  List<Map<String, dynamic>> data = [
    {
      'title': 'Native App',
      'platform': 'Android, iOS',
      'desc': 'Bawaan Dari OS',
      'lang': 'Swift, Kotlin, Dart, C#',
      'color': Colors.blue,
    },
    {
      'title': 'Hybrid App',
      'platform': 'Android, iOS, Web',
      'desc': 'Javascript base',
      'lang': 'React, Vue, Ionic',
      'color': Colors.grey,
    },
  ];

  var txtJudul = TextEditingController();
  var txtPlatform = TextEditingController();
  var txtLangprog = TextEditingController();
  var txtDeskripsi = TextEditingController();
  List<String> colors = ['blue', 'green', 'silver'];
  List<DropdownMenuItem<String>> dropItems = <DropdownMenuItem<String>>[];
  String? col_selected;

  @override
  void initState() {
    super.initState();
    for (String col in colors) {
      dropItems.add(
        DropdownMenuItem(
          value: col,
          child: Text(col),
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: SafeArea(
        child: ListView.builder(
          itemCount: data.length,
          itemBuilder: (context, index) {
            return Card(
              color: Colors.white,
              child: Container(
                padding: const EdgeInsets.only(left: 10),
                child: Row(
                  children: [
                    Container(
                      width: 10,
                      height: 130,
                      decoration: BoxDecoration(
                        color: data[index]['color'],
                      ),
                    ),
                    Container(
                      margin: const EdgeInsets.only(left: 10, top: 10, bottom: 10),
                      padding: const EdgeInsets.only(top: 10),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(data[index]['title'], style: const TextStyle(
                              color: Colors.blue,
                              fontSize: 20)),
                          Text(data[index]['platform'], style: const TextStyle(
                              fontSize: 16)),
                          Text(data[index]['desc'], style: const TextStyle(
                              fontSize: 14)),
                          Text('Lang: ${data[index]['lang']}', style: const TextStyle(
                              fontSize: 12)),
                        ],
                      ),
                    ),
                  ],
                ),
              ),
            );
          },
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          var snackBar = SnackBar(
            content: const Text('Add New Item?'),
            action: SnackBarAction(
              label: 'Yes',
              onPressed: () {
                showDialog(
                  context: context,
                  builder: (BuildContext context) {
                    return AlertDialog(
                      title: const Text('Isi Data Input'),
                      content: SingleChildScrollView(
                        child: Column(
                          children: [
                            TextField(
                              decoration: const InputDecoration(
                                labelText: 'Tech Name',
                              ),
                              controller: txtJudul,
                            ),
                            TextField(
                              decoration: const InputDecoration(
                                labelText: 'Platform',
                              ),
                              controller: txtPlatform,
                            ),
                            TextField(
                              decoration: const InputDecoration(
                                labelText: 'Deskripsi',
                              ),
                              controller: txtDeskripsi,
                            ),
                            TextField(
                              decoration: const InputDecoration(
                                labelText: 'Lang',
                              ),
                              controller: txtLangprog,
                            ),
                            DropdownButtonFormField<String>(
                              items: dropItems,
                              onChanged: (val) {
                                col_selected = val;
                              },
                              decoration: const InputDecoration(
                                labelText: 'Color',
                              ),
                            ),
                          ],
                        ),
                      ),
                      actions: <Widget>[
                        ElevatedButton(
                          child: const Text('Close'),
                          onPressed: () {
                            Navigator.of(context).pop();
                          },
                        ),
                        ElevatedButton(
                          child: const Text('Submit'),
                          onPressed: () {
                            setState(() {
                              Color colSelected;
                              if (col_selected == 'blue') {
                                colSelected = Colors.blue;
                              } else if (col_selected == 'green') {
                                colSelected = Colors.green;
                              } else {
                                colSelected = Colors.grey;
                              }

                              data.add({
                                'title': txtJudul.text,
                                'platform': txtPlatform.text,
                                'desc': txtDeskripsi.text,
                                'lang': txtLangprog.text,
                                'color': colSelected,
                              });
                            });
                            Navigator.of(context).pop();
                          },
                        ),
                      ],
                    );
                  },
                );
              },
            ),
          );
          ScaffoldMessenger.of(context).showSnackBar(snackBar);
        },
        child: const Icon(Icons.add),
      ),
    );
  }
}