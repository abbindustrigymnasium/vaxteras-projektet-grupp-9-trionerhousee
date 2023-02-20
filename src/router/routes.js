
const routes = [
  {
    path: '/',
    component: () => import('layouts/MainLayout.vue'),
    children: [
      { path: '', component: () => import('pages/IndexPage.vue') },
      { path: 'Setting', component: () => import('pages/Settings.vue') },
      { path: 'AboutUs', component: () => import('pages/AboutUs.vue') },
      { path: 'Statistics', component: () => import('pages/Statistics.vue') },
      {path: 'setup', component: () => import('pages/setup.vue')},
      {path: 'Galleri', component: () => import('pages/galleriPage.vue')},


    ]
  },

  // Always leave this as last one,
  // but you can also remove it
  {
    path: '/:catchAll(.*)*',
    component: () => import('pages/ErrorNotFound.vue')
  }
]

export default routes
