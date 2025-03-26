import os

path = os.getcwd()

def _write_entry(writter, solutions_path, chapter, file, splitter):
    with open(os.path.join(solutions_path, os.path.join(chapter, file)), 'r') as reader:
        line = reader.readline()
        try:
            line = line.split(splitter)[1].strip()
        except KeyboardInterrupt:
            raise KeyboardInterrupt
        except:
            print('ERROR: ' + chapter + ' ' + file)
        writter.write('- [%s](https://github.com/saurabh-kadian/cp3uva/blob/master/solutions/%s/%s)\n' % (line, chapter, file))

def generate_readme():
    with open(os.path.join(path, 'README.md'), 'w') as writter:
        writter.write('# cp3uva' + '\n')
        writter.write('Problems listed on [Uhunt](https://uhunt.onlinejudge.org) marked under Competitive Programming 3, a book by Steven Halim and Felix Halim. \nCredit: Steven Halim, Felix Halim and team for the compilation.' + '\n')
        writter.write('\n')
        writter.write('Link to my [Uhunt ID](https://uhunt.onlinejudge.org/id/384732), inline. \n')
        writter.write('\n')
        writter.write('## Links to solved problems in the repository' + '\n')
        
        solutions_path = os.path.join(path, 'solutions')
        for chapter in os.listdir(solutions_path):
            writter.write('\n### %s\n\n' % chapter)
            for file in os.listdir(os.path.join(solutions_path, chapter)):
                if '.cpp' in file:
                    _write_entry(writter, solutions_path, chapter, file, "//")
                elif '.py' in file:
                    _write_entry(writter, solutions_path, chapter, file, "#")
                else:
                    print("Not generating entry for %s" % os.path.join(solutions_path, os.path.join(chapter, file)))
