#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>

#include <taskflow/taskflow.hpp>
#include <vector>
#include <utility>
#include <chrono>
#include <limits.h>

// --------------------------------------------------------
// Testcase: for_each
// --------------------------------------------------------

enum TYPE {
  GUIDED,
  DYNAMIC,
  STATIC
};

void for_each(unsigned W, TYPE type) {

  tf::Executor executor(W);
  tf::Taskflow taskflow;
  
  std::vector<int> vec(1024);
  for(int n = 0; n <= 150; n++) {

    std::fill_n(vec.begin(), vec.size(), -1);

    int beg = ::rand()%300 - 150;
    int end = beg + n;

    for(int s=1; s<=16; s*=2) {
      for(int c=0; c<=17; c=c*2+1) {
        taskflow.clear();
        std::atomic<int> counter {0};
        
        switch(type) {
          case GUIDED:
            taskflow.for_each_index_guided(beg, end, s, [&](int i){
              counter++;
              vec[i-beg] = i;
            }, c);
          break;

          case DYNAMIC:
            taskflow.for_each_index_dynamic(beg, end, s, [&](int i){
              counter++;
              vec[i-beg] = i;
            }, c);
          break;
          
          case STATIC:
            taskflow.for_each_index_static(beg, end, s, [&](int i){
              counter++;
              vec[i-beg] = i;
            }, c);
          break;
        }

        executor.run(taskflow).wait();
        REQUIRE(counter == (n + s - 1) / s);

        for(int i=beg; i<end; i+=s) {
          REQUIRE(vec[i-beg] == i);
          vec[i-beg] = -1;
        }

        for(const auto i : vec) {
          REQUIRE(i == -1);
        }
      }
    }
  }

  for(size_t n = 0; n < 150; n++) {
    for(size_t c=0; c<=17; c=c*2+1) {
    
      std::fill_n(vec.begin(), vec.size(), -1);

      taskflow.clear();
      std::atomic<int> counter {0};
      
      switch(type) {
        case GUIDED:
          taskflow.for_each_guided(vec.begin(), vec.begin() + n, [&](int& i){
            counter++;
            i = 1;
          }, c);
        break;

        case DYNAMIC:
          taskflow.for_each_dynamic(vec.begin(), vec.begin() + n, [&](int& i){
            counter++;
            i = 1;
          }, c);
        break;
        
        case STATIC:
          taskflow.for_each_static(vec.begin(), vec.begin() + n, [&](int& i){
            counter++;
            i = 1;
          }, c);
        break;
      }

      executor.run(taskflow).wait();
      REQUIRE(counter == n);

      for(size_t i=0; i<n; ++i) {
        REQUIRE(vec[i] == 1);
      }

      for(size_t i=n; i<vec.size(); ++i) {
        REQUIRE(vec[i] == -1);
      }
    }
  }
}

// guided
TEST_CASE("pfg.1thread" * doctest::timeout(300)) {
  for_each(1, GUIDED);
}

TEST_CASE("pfg.2threads" * doctest::timeout(300)) {
  for_each(2, GUIDED);
}

TEST_CASE("pfg.3threads" * doctest::timeout(300)) {
  for_each(3, GUIDED);
}

TEST_CASE("pfg.4threads" * doctest::timeout(300)) {
  for_each(4, GUIDED);
}

TEST_CASE("pfg.5threads" * doctest::timeout(300)) {
  for_each(5, GUIDED);
}

TEST_CASE("pfg.6threads" * doctest::timeout(300)) {
  for_each(6, GUIDED);
}

TEST_CASE("pfg.7threads" * doctest::timeout(300)) {
  for_each(7, GUIDED);
}

TEST_CASE("pfg.8threads" * doctest::timeout(300)) {
  for_each(8, GUIDED);
}

TEST_CASE("pfg.9threads" * doctest::timeout(300)) {
  for_each(9, GUIDED);
}

TEST_CASE("pfg.10threads" * doctest::timeout(300)) {
  for_each(10, GUIDED);
}

TEST_CASE("pfg.11threads" * doctest::timeout(300)) {
  for_each(11, GUIDED);
}

TEST_CASE("pfg.12threads" * doctest::timeout(300)) {
  for_each(12, GUIDED);
}

// dynamic
TEST_CASE("pfd.1thread" * doctest::timeout(300)) {
  for_each(1, DYNAMIC);
}

TEST_CASE("pfd.2threads" * doctest::timeout(300)) {
  for_each(2, DYNAMIC);
}

TEST_CASE("pfd.3threads" * doctest::timeout(300)) {
  for_each(3, DYNAMIC);
}

TEST_CASE("pfd.4threads" * doctest::timeout(300)) {
  for_each(4, DYNAMIC);
}

TEST_CASE("pfd.5threads" * doctest::timeout(300)) {
  for_each(5, DYNAMIC);
}

TEST_CASE("pfd.6threads" * doctest::timeout(300)) {
  for_each(6, DYNAMIC);
}

TEST_CASE("pfd.7threads" * doctest::timeout(300)) {
  for_each(7, DYNAMIC);
}

TEST_CASE("pfd.8threads" * doctest::timeout(300)) {
  for_each(8, DYNAMIC);
}

TEST_CASE("pfd.9threads" * doctest::timeout(300)) {
  for_each(9, DYNAMIC);
}

TEST_CASE("pfd.10threads" * doctest::timeout(300)) {
  for_each(10, DYNAMIC);
}

TEST_CASE("pfd.11threads" * doctest::timeout(300)) {
  for_each(11, DYNAMIC);
}

TEST_CASE("pfd.12threads" * doctest::timeout(300)) {
  for_each(12, DYNAMIC);
}

// static
TEST_CASE("pfs.1thread" * doctest::timeout(300)) {
  for_each(1, STATIC);
}

TEST_CASE("pfs.2threads" * doctest::timeout(300)) {
  for_each(2, STATIC);
}

TEST_CASE("pfs.3threads" * doctest::timeout(300)) {
  for_each(3, STATIC);
}

TEST_CASE("pfs.4threads" * doctest::timeout(300)) {
  for_each(4, STATIC);
}

TEST_CASE("pfs.5threads" * doctest::timeout(300)) {
  for_each(5, STATIC);
}

TEST_CASE("pfs.6threads" * doctest::timeout(300)) {
  for_each(6, STATIC);
}

TEST_CASE("pfs.7threads" * doctest::timeout(300)) {
  for_each(7, STATIC);
}

TEST_CASE("pfs.8threads" * doctest::timeout(300)) {
  for_each(8, STATIC);
}

TEST_CASE("pfs.9threads" * doctest::timeout(300)) {
  for_each(9, STATIC);
}

TEST_CASE("pfs.10threads" * doctest::timeout(300)) {
  for_each(10, STATIC);
}

TEST_CASE("pfs.11threads" * doctest::timeout(300)) {
  for_each(11, STATIC);
}

TEST_CASE("pfs.12threads" * doctest::timeout(300)) {
  for_each(12, STATIC);
}

// ----------------------------------------------------------------------------
// stateful_for_each
// ----------------------------------------------------------------------------

void stateful_for_each(unsigned W, TYPE type) {
  
  tf::Executor executor(W);
  tf::Taskflow taskflow;
  std::vector<int> vec;
  std::atomic<int> counter {0};
  
  for(size_t n = 0; n <= 150; n++) {
    for(size_t c=0; c<=17; c++) {
  
    std::vector<int>::iterator beg, end;
    size_t ibeg = 0, iend = 0;
    size_t half = n/2;
    
    taskflow.clear();
    
    auto init = taskflow.emplace([&](){ 
      vec.resize(n);
      std::fill_n(vec.begin(), vec.size(), -1);

      beg = vec.begin();
      end = beg + half;

      ibeg = half;
      iend = n;

      counter = 0;
    });

    tf::Task pf1, pf2;
    
    switch (type) {

      case GUIDED:
        pf1 = taskflow.for_each_guided(
          std::ref(beg), std::ref(end), [&](int& i){
          counter++;
          i = 8;
        }, c);

        pf2 = taskflow.for_each_index_guided(
          std::ref(ibeg), std::ref(iend), size_t{1}, [&] (size_t i) {
            counter++;
            vec[i] = -8;
        }, c);
      break;

      case DYNAMIC:
        pf1 = taskflow.for_each_dynamic(
          std::ref(beg), std::ref(end), [&](int& i){
          counter++;
          i = 8;
        }, c);

        pf2 = taskflow.for_each_index_dynamic(
          std::ref(ibeg), std::ref(iend), size_t{1}, [&] (size_t i) {
            counter++;
            vec[i] = -8;
        }, c);
      break;
      
      case STATIC:
        pf1 = taskflow.for_each_static(
          std::ref(beg), std::ref(end), [&](int& i){
          counter++;
          i = 8;
        }, c);

        pf2 = taskflow.for_each_index_static(
          std::ref(ibeg), std::ref(iend), size_t{1}, [&] (size_t i) {
            counter++;
            vec[i] = -8;
        }, c);
      break;
    }

    init.precede(pf1, pf2);

    executor.run(taskflow).wait();
    REQUIRE(counter == n);

    for(size_t i=0; i<half; ++i) {
      REQUIRE(vec[i] == 8);
      vec[i] = 0;
    }

    for(size_t i=half; i<n; ++i) {
      REQUIRE(vec[i] == -8);
      vec[i] = 0;
    }
    }
  }
}

// guided
TEST_CASE("statefulpfg.1thread" * doctest::timeout(300)) {
  stateful_for_each(1, GUIDED);
}

TEST_CASE("statefulpfg.2threads" * doctest::timeout(300)) {
  stateful_for_each(2, GUIDED);
}

TEST_CASE("statefulpfg.3threads" * doctest::timeout(300)) {
  stateful_for_each(3, GUIDED);
}

TEST_CASE("statefulpfg.4threads" * doctest::timeout(300)) {
  stateful_for_each(4, GUIDED);
}

TEST_CASE("statefulpfg.5threads" * doctest::timeout(300)) {
  stateful_for_each(5, GUIDED);
}

TEST_CASE("statefulpfg.6threads" * doctest::timeout(300)) {
  stateful_for_each(6, GUIDED);
}

TEST_CASE("statefulpfg.7threads" * doctest::timeout(300)) {
  stateful_for_each(7, GUIDED);
}

TEST_CASE("statefulpfg.8threads" * doctest::timeout(300)) {
  stateful_for_each(8, GUIDED);
}

TEST_CASE("statefulpfg.9threads" * doctest::timeout(300)) {
  stateful_for_each(9, GUIDED);
}

TEST_CASE("statefulpfg.10threads" * doctest::timeout(300)) {
  stateful_for_each(10, GUIDED);
}

TEST_CASE("statefulpfg.11threads" * doctest::timeout(300)) {
  stateful_for_each(11, GUIDED);
}

TEST_CASE("statefulpfg.12threads" * doctest::timeout(300)) {
  stateful_for_each(12, GUIDED);
}

// dynamic
TEST_CASE("statefulpfd.1thread" * doctest::timeout(300)) {
  stateful_for_each(1, DYNAMIC);
}

TEST_CASE("statefulpfd.2threads" * doctest::timeout(300)) {
  stateful_for_each(2, DYNAMIC);
}

TEST_CASE("statefulpfd.3threads" * doctest::timeout(300)) {
  stateful_for_each(3, DYNAMIC);
}

TEST_CASE("statefulpfd.4threads" * doctest::timeout(300)) {
  stateful_for_each(4, DYNAMIC);
}

TEST_CASE("statefulpfd.5threads" * doctest::timeout(300)) {
  stateful_for_each(5, DYNAMIC);
}

TEST_CASE("statefulpfd.6threads" * doctest::timeout(300)) {
  stateful_for_each(6, DYNAMIC);
}

TEST_CASE("statefulpfd.7threads" * doctest::timeout(300)) {
  stateful_for_each(7, DYNAMIC);
}

TEST_CASE("statefulpfd.8threads" * doctest::timeout(300)) {
  stateful_for_each(8, DYNAMIC);
}

TEST_CASE("statefulpfd.9threads" * doctest::timeout(300)) {
  stateful_for_each(9, DYNAMIC);
}

TEST_CASE("statefulpfd.10threads" * doctest::timeout(300)) {
  stateful_for_each(10, DYNAMIC);
}

TEST_CASE("statefulpfd.11threads" * doctest::timeout(300)) {
  stateful_for_each(11, DYNAMIC);
}

TEST_CASE("statefulpfd.12threads" * doctest::timeout(300)) {
  stateful_for_each(12, DYNAMIC);
}

// static
TEST_CASE("statefulpfs.1thread" * doctest::timeout(300)) {
  stateful_for_each(1, STATIC);
}

TEST_CASE("statefulpfs.2threads" * doctest::timeout(300)) {
  stateful_for_each(2, STATIC);
}

TEST_CASE("statefulpfs.3threads" * doctest::timeout(300)) {
  stateful_for_each(3, STATIC);
}

TEST_CASE("statefulpfs.4threads" * doctest::timeout(300)) {
  stateful_for_each(4, STATIC);
}

TEST_CASE("statefulpfs.5threads" * doctest::timeout(300)) {
  stateful_for_each(5, STATIC);
}

TEST_CASE("statefulpfs.6threads" * doctest::timeout(300)) {
  stateful_for_each(6, STATIC);
}

TEST_CASE("statefulpfs.7threads" * doctest::timeout(300)) {
  stateful_for_each(7, STATIC);
}

TEST_CASE("statefulpfs.8threads" * doctest::timeout(300)) {
  stateful_for_each(8, STATIC);
}

TEST_CASE("statefulpfs.9threads" * doctest::timeout(300)) {
  stateful_for_each(9, STATIC);
}

TEST_CASE("statefulpfs.10threads" * doctest::timeout(300)) {
  stateful_for_each(10, STATIC);
}

TEST_CASE("statefulpfs.11threads" * doctest::timeout(300)) {
  stateful_for_each(11, STATIC);
}

TEST_CASE("statefulpfs.12threads" * doctest::timeout(300)) {
  stateful_for_each(12, STATIC);
}

// --------------------------------------------------------
// Testcase: reduce
// --------------------------------------------------------

void reduce(unsigned W, TYPE type) {

  tf::Executor executor(W);
  tf::Taskflow taskflow;

  std::vector<int> vec(1000);

  for(auto& i : vec) i = ::rand() % 100 - 50;

  for(size_t n=1; n<vec.size(); n++) {
    for(size_t c=0; c<=17; c=c*2+1) {

      int smin = std::numeric_limits<int>::max();
      int pmin = std::numeric_limits<int>::max();
      auto beg = vec.end();
      auto end = vec.end();

      taskflow.clear();
      auto stask = taskflow.emplace([&](){
        beg = vec.begin();
        end = vec.begin() + n;
        for(auto itr = beg; itr != end; itr++) {
          smin = std::min(*itr, smin);
        }
      });

      tf::Task ptask;

      switch (type) {
        case GUIDED:
          ptask = taskflow.reduce_guided(
            std::ref(beg), std::ref(end), pmin, [](int& l, int& r){
            return std::min(l, r);
          }, c);
        break;

        case DYNAMIC:
          ptask = taskflow.reduce_dynamic(
            std::ref(beg), std::ref(end), pmin, [](int& l, int& r){
            return std::min(l, r);
          }, c);
        break;
        
        case STATIC:
          ptask = taskflow.reduce_static(
            std::ref(beg), std::ref(end), pmin, [](int& l, int& r){
            return std::min(l, r);
          }, c);
        break;
      }

      stask.precede(ptask);

      executor.run(taskflow).wait();
      
      REQUIRE(smin != std::numeric_limits<int>::max());
      REQUIRE(pmin != std::numeric_limits<int>::max());
      REQUIRE(smin == pmin);
    }
  }
}

// guided
TEST_CASE("prg.1thread" * doctest::timeout(300)) {
  reduce(1, GUIDED);
}

TEST_CASE("prg.2threads" * doctest::timeout(300)) {
  reduce(2, GUIDED);
}

TEST_CASE("prg.3threads" * doctest::timeout(300)) {
  reduce(3, GUIDED);
}

TEST_CASE("prg.4threads" * doctest::timeout(300)) {
  reduce(4, GUIDED);
}

TEST_CASE("prg.5threads" * doctest::timeout(300)) {
  reduce(5, GUIDED);
}

TEST_CASE("prg.6threads" * doctest::timeout(300)) {
  reduce(6, GUIDED);
}

TEST_CASE("prg.7threads" * doctest::timeout(300)) {
  reduce(7, GUIDED);
}

TEST_CASE("prg.8threads" * doctest::timeout(300)) {
  reduce(8, GUIDED);
}

TEST_CASE("prg.9threads" * doctest::timeout(300)) {
  reduce(9, GUIDED);
}

TEST_CASE("prg.10threads" * doctest::timeout(300)) {
  reduce(10, GUIDED);
}

TEST_CASE("prg.11threads" * doctest::timeout(300)) {
  reduce(11, GUIDED);
}

TEST_CASE("prg.12threads" * doctest::timeout(300)) {
  reduce(12, GUIDED);
}

// dynamic
TEST_CASE("prd.1thread" * doctest::timeout(300)) {
  reduce(1, DYNAMIC);
}

TEST_CASE("prd.2threads" * doctest::timeout(300)) {
  reduce(2, DYNAMIC);
}

TEST_CASE("prd.3threads" * doctest::timeout(300)) {
  reduce(3, DYNAMIC);
}

TEST_CASE("prd.4threads" * doctest::timeout(300)) {
  reduce(4, DYNAMIC);
}

TEST_CASE("prd.5threads" * doctest::timeout(300)) {
  reduce(5, DYNAMIC);
}

TEST_CASE("prd.6threads" * doctest::timeout(300)) {
  reduce(6, DYNAMIC);
}

TEST_CASE("prd.7threads" * doctest::timeout(300)) {
  reduce(7, DYNAMIC);
}

TEST_CASE("prd.8threads" * doctest::timeout(300)) {
  reduce(8, DYNAMIC);
}

TEST_CASE("prd.9threads" * doctest::timeout(300)) {
  reduce(9, DYNAMIC);
}

TEST_CASE("prd.10threads" * doctest::timeout(300)) {
  reduce(10, DYNAMIC);
}

TEST_CASE("prd.11threads" * doctest::timeout(300)) {
  reduce(11, DYNAMIC);
}

TEST_CASE("prd.12threads" * doctest::timeout(300)) {
  reduce(12, DYNAMIC);
}

// static
TEST_CASE("prs.1thread" * doctest::timeout(300)) {
  reduce(1, STATIC);
}

TEST_CASE("prs.2threads" * doctest::timeout(300)) {
  reduce(2, STATIC);
}

TEST_CASE("prs.3threads" * doctest::timeout(300)) {
  reduce(3, STATIC);
}

TEST_CASE("prs.4threads" * doctest::timeout(300)) {
  reduce(4, STATIC);
}

TEST_CASE("prs.5threads" * doctest::timeout(300)) {
  reduce(5, STATIC);
}

TEST_CASE("prs.6threads" * doctest::timeout(300)) {
  reduce(6, STATIC);
}

TEST_CASE("prs.7threads" * doctest::timeout(300)) {
  reduce(7, STATIC);
}

TEST_CASE("prs.8threads" * doctest::timeout(300)) {
  reduce(8, STATIC);
}

TEST_CASE("prs.9threads" * doctest::timeout(300)) {
  reduce(9, STATIC);
}

TEST_CASE("prs.10threads" * doctest::timeout(300)) {
  reduce(10, STATIC);
}

TEST_CASE("prs.11threads" * doctest::timeout(300)) {
  reduce(11, STATIC);
}

TEST_CASE("prs.12threads" * doctest::timeout(300)) {
  reduce(12, STATIC);
}

// ----------------------------------------------------------------------------
// transform_reduce
// ----------------------------------------------------------------------------

class Data {

  private:

    int _v {::rand() % 100 - 50};
  
  public:

    int get() const { return _v; }
};

void transform_reduce(unsigned W, TYPE type) {

  tf::Executor executor(W);
  tf::Taskflow taskflow;

  std::vector<Data> vec(1000);

  for(size_t n=1; n<vec.size(); n++) {
    for(size_t c=0; c<=17; c=c*2+1) {

      int smin = std::numeric_limits<int>::max();
      int pmin = std::numeric_limits<int>::max();
      auto beg = vec.end();
      auto end = vec.end();

      taskflow.clear();
      auto stask = taskflow.emplace([&](){
        beg = vec.begin();
        end = vec.begin() + n;
        for(auto itr = beg; itr != end; itr++) {
          smin = std::min(itr->get(), smin);
        }
      });

      tf::Task ptask;

      switch (type) {
        case GUIDED:
          ptask = taskflow.transform_reduce_guided(
            std::ref(beg), std::ref(end), pmin, 
            [] (int l, int r)   { return std::min(l, r); }, 
            [] (const Data& data) { return data.get(); },
            c
          );
        break;
        
        case STATIC:
          ptask = taskflow.transform_reduce_static(
            std::ref(beg), std::ref(end), pmin, 
            [] (int l, int r)   { return std::min(l, r); }, 
            [] (const Data& data) { return data.get(); },
            c
          );
        break;
        
        case DYNAMIC:
          ptask = taskflow.transform_reduce_dynamic(
            std::ref(beg), std::ref(end), pmin, 
            [] (int l, int r)   { return std::min(l, r); }, 
            [] (const Data& data) { return data.get(); },
            c
          );
        break;
      }

      stask.precede(ptask);

      executor.run(taskflow).wait();
      
      REQUIRE(smin != std::numeric_limits<int>::max());
      REQUIRE(pmin != std::numeric_limits<int>::max());
      REQUIRE(smin == pmin);
    }
  }
}

// guided
TEST_CASE("ptrg.1thread" * doctest::timeout(300)) {
  transform_reduce(1, GUIDED);
}

TEST_CASE("ptrg.2threads" * doctest::timeout(300)) {
  transform_reduce(2, GUIDED);
}

TEST_CASE("ptrg.3threads" * doctest::timeout(300)) {
  transform_reduce(3, GUIDED);
}

TEST_CASE("ptrg.4threads" * doctest::timeout(300)) {
  transform_reduce(4, GUIDED);
}

TEST_CASE("ptrg.5threads" * doctest::timeout(300)) {
  transform_reduce(5, GUIDED);
}

TEST_CASE("ptrg.6threads" * doctest::timeout(300)) {
  transform_reduce(6, GUIDED);
}

TEST_CASE("ptrg.7threads" * doctest::timeout(300)) {
  transform_reduce(7, GUIDED);
}

TEST_CASE("ptrg.8threads" * doctest::timeout(300)) {
  transform_reduce(8, GUIDED);
}

TEST_CASE("ptrg.9threads" * doctest::timeout(300)) {
  transform_reduce(9, GUIDED);
}

TEST_CASE("ptrg.10threads" * doctest::timeout(300)) {
  transform_reduce(10, GUIDED);
}

TEST_CASE("ptrg.11threads" * doctest::timeout(300)) {
  transform_reduce(11, GUIDED);
}

TEST_CASE("ptrg.12threads" * doctest::timeout(300)) {
  transform_reduce(12, GUIDED);
}

// dynamic
TEST_CASE("ptrd.1thread" * doctest::timeout(300)) {
  transform_reduce(1, DYNAMIC);
}

TEST_CASE("ptrd.2threads" * doctest::timeout(300)) {
  transform_reduce(2, DYNAMIC);
}

TEST_CASE("ptrd.3threads" * doctest::timeout(300)) {
  transform_reduce(3, DYNAMIC);
}

TEST_CASE("ptrd.4threads" * doctest::timeout(300)) {
  transform_reduce(4, DYNAMIC);
}

TEST_CASE("ptrd.5threads" * doctest::timeout(300)) {
  transform_reduce(5, DYNAMIC);
}

TEST_CASE("ptrd.6threads" * doctest::timeout(300)) {
  transform_reduce(6, DYNAMIC);
}

TEST_CASE("ptrd.7threads" * doctest::timeout(300)) {
  transform_reduce(7, DYNAMIC);
}

TEST_CASE("ptrd.8threads" * doctest::timeout(300)) {
  transform_reduce(8, DYNAMIC);
}

TEST_CASE("ptrd.9threads" * doctest::timeout(300)) {
  transform_reduce(9, DYNAMIC);
}

TEST_CASE("ptrd.10threads" * doctest::timeout(300)) {
  transform_reduce(10, DYNAMIC);
}

TEST_CASE("ptrd.11threads" * doctest::timeout(300)) {
  transform_reduce(11, DYNAMIC);
}

TEST_CASE("ptrd.12threads" * doctest::timeout(300)) {
  transform_reduce(12, DYNAMIC);
}

// static
TEST_CASE("ptrs.1thread" * doctest::timeout(300)) {
  transform_reduce(1, STATIC);
}

TEST_CASE("ptrs.2threads" * doctest::timeout(300)) {
  transform_reduce(2, STATIC);
}

TEST_CASE("ptrs.3threads" * doctest::timeout(300)) {
  transform_reduce(3, STATIC);
}

TEST_CASE("ptrs.4threads" * doctest::timeout(300)) {
  transform_reduce(4, STATIC);
}

TEST_CASE("ptrs.5threads" * doctest::timeout(300)) {
  transform_reduce(5, STATIC);
}

TEST_CASE("ptrs.6threads" * doctest::timeout(300)) {
  transform_reduce(6, STATIC);
}

TEST_CASE("ptrs.7threads" * doctest::timeout(300)) {
  transform_reduce(7, STATIC);
}

TEST_CASE("ptrs.8threads" * doctest::timeout(300)) {
  transform_reduce(8, STATIC);
}

TEST_CASE("ptrs.9threads" * doctest::timeout(300)) {
  transform_reduce(9, STATIC);
}

TEST_CASE("ptrs.10threads" * doctest::timeout(300)) {
  transform_reduce(10, STATIC);
}

TEST_CASE("ptrs.11threads" * doctest::timeout(300)) {
  transform_reduce(11, STATIC);
}

TEST_CASE("ptrs.12threads" * doctest::timeout(300)) {
  transform_reduce(12, STATIC);
}

