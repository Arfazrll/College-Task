import 'package:flutter/material.dart';
import 'main.dart';

void main() {
  runApp(const MyApp11_1());
}

class MyApp11_1 extends StatelessWidget {
  const MyApp11_1({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'APB',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePageNav(title: 'APB'),
      debugShowCheckedModeBanner: false,
    );
  }
}

class MyHomePageNav extends StatefulWidget {
  const MyHomePageNav({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  _MyHomePageNavState createState() => _MyHomePageNavState();
}

class _MyHomePageNavState extends State<MyHomePageNav> {
  int selected = 0;
  PageController pc = PageController(initialPage: 0);

  @override
  void dispose() {
    pc.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: SafeArea(
        child: PageView(
          controller: pc,
          onPageChanged: (index) {
            setState(() {
              selected = index;
            });
          },
          children: [
            Center(
              child: InkWell(
                child: const Text('Go to Home page',
                    style: TextStyle(fontSize: 30)),
                onTap: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => const MyApp(),
                    ),
                  );
                },
              ),
            ),
            const Center(
              child: Text('Email page', style: TextStyle(fontSize: 30)),
            ),
            const Center(
              child: Text('Profile page', style: TextStyle(fontSize: 30)),
            ),
          ],
        ),
      ),
      bottomNavigationBar: BottomNavigationBar(
        type: BottomNavigationBarType.fixed,
        backgroundColor: Colors.blue,
        selectedItemColor: Colors.deepOrange,
        unselectedItemColor: Colors.white,
        currentIndex: selected,
        onTap: (index) {
          setState(() {
            selected = index;
          });
          pc.animateToPage(
            index,
            duration: const Duration(milliseconds: 200),
            curve: Curves.linear,
          );
        },
        items: const [
          BottomNavigationBarItem(
            icon: Icon(Icons.home_filled),
            label: 'Home',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.email),
            label: 'Email',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.person),
            label: 'Profile',
          ),
        ],
      ),
    );
  }
}