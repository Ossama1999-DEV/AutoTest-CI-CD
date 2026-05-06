# 🚀 CI/CD Setup with Jenkins + Docker

## 📌 Overview

This project demonstrates a complete **CI/CD pipeline** using:

* Jenkins
* Docker
* GitHub
* C project (Makefile based)

The goal is to build, run, and archive a C application automatically.

---

## 🧱 Project Structure

```
.
├── Jenkinsfile
├── tools
│   ├── Makefile
│   ├── src
│   │   └── main.c
│   └── build
```

---

## ⚙️ Prerequisites

* Docker installed
* WSL2 (for Windows users)
* GitHub repository

---

## 🐳 Step 1 — Create Jenkins Docker Image

Create a `Dockerfile`:

```Dockerfile
FROM jenkins/jenkins:lts

USER root

RUN apt-get update && apt-get install -y docker.io

USER jenkins
```

Build the image:

```bash
docker build -t jenkins-docker .
```

---

## 🚀 Step 2 — Run Jenkins Container

```bash
docker run -d \
  -p 8080:8080 \
  -p 50000:50000 \
  -v /var/run/docker.sock:/var/run/docker.sock \
  -u root \
  --name jenkins \
  jenkins-docker
```

---

## 🔑 Step 3 — Unlock Jenkins

Get initial password:

```bash
docker exec jenkins cat /var/jenkins_home/secrets/initialAdminPassword
```

Open in browser:

```
http://localhost:8080
```

* Install suggested plugins
* Create admin user

---

## 🔌 Step 4 — Install Required Plugin

In Jenkins:

```
Manage Jenkins → Plugins → Available
```

Install:

* Docker Pipeline

---

## 🔗 Step 5 — Configure Pipeline Job

* New Item → Pipeline
* Definition: Pipeline script from SCM
* SCM: Git
* Repository: your GitHub repo
* Branch: `main`
* Script Path: `Jenkinsfile`

---

## 🧪 Step 6 — Jenkinsfile

```groovy
pipeline {
    agent {
        docker {
            image 'gcc:latest'
        }
    }

    stages {
        stage('Build') {
            steps {
                sh 'cd tools && make'
            }
        }

        stage('Run') {
            steps {
                sh 'cd tools && ./app'
            }
        }

        stage('Archive') {
            steps {
                archiveArtifacts artifacts: 'tools/app', fingerprint: true
            }
        }
    }
}
```

---

## ⚠️ Common Issues & Fixes

### ❌ docker: not found

👉 Jenkins container does not have Docker installed
✔️ Fix: use custom Docker image

---

### ❌ permission denied (docker.sock)

```bash
permission denied while trying to connect to docker daemon
```

✔️ Quick fix:

```bash
sudo chmod 666 /var/run/docker.sock
```

---

### ❌ wrong branch (master vs main)

✔️ Fix:

```
*/main
```

---

## 🎯 Expected Result

* Jenkins pulls repo from GitHub
* Runs pipeline
* Builds C project
* Executes program
* Archives binary

---

## 🧠 Key Learnings

* Jenkins pipeline basics
* Docker integration in CI
* Handling permissions in containers
* Reproducible build environments

---

## 🚀 Next Steps

* Add GitHub webhook (auto build)
* Add unit tests
* Add linting (clang-format / cppcheck)
* Multi-stage pipelines
* Docker image build & push

---

## 👨‍💻 Author

Oussama DBIBIH
Embedded Systems Engineer | CI/CD | C/C++ | DevOps

---
